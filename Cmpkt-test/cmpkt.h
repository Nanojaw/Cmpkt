#pragma once

namespace cmpkt
{
	inline void Save(const std::string& data, const std::string& filename)
    {
        std::cout << filename << ": " << data << std::endl;
    }

    template<typename T>
	std::string Serialize_Primitives(T primitive)
    {
		std::string result;
	    switch (sizeof primitive)
	    {
	    case 1:
			result += *(char*)&primitive;
			break;
	    case 2:
			result += *(char*)&primitive;
			result += ((char*)&primitive)[1];
			break;
	    case 4:
			result += *(char*)&primitive;
			result += ((char*)&primitive)[1];
			result += ((char*)&primitive)[2];
			result += ((char*)&primitive)[3];
			break;
	    case 8:
			result += *(char*)&primitive;
			result += ((char*)&primitive)[1];
			result += ((char*)&primitive)[2];
			result += ((char*)&primitive)[3];
			result += ((char*)&primitive)[4];
			result += ((char*)&primitive)[5];
			result += ((char*)&primitive)[6];
			result += ((char*)&primitive)[7];
			break;
		default: break;
	    }

		return result;
    }

	template<typename T>
	std::string Serialize_Array(T* array, int size)
    {
    	std::string result = Serialize_Primitives(size);
	    for (int i = 0; i < size; i++) result += Serialize_Primitives(array[i]);
    	return result;
    }

	class Deserializer
	{
	public:
		std::string Serialized;

		explicit Deserializer(const std::string& serialized) : Serialized(serialized) {}

		int DeserializeInt(int index) { return *(int*)&Serialized[index]; }
		bool DeserializeBool(int index) { return *(bool*)&Serialized[index]; }
		char DeserializeChar(int index) { return Serialized[index]; }
		wchar_t DeserializeWchar(int index) { return *(wchar_t*)&Serialized[index]; }
		float DeserializeFloat(int index) { return *(float*)&Serialized[index]; }
		double DeserializeDouble(int index) { return *(double*)&Serialized[index]; }

		std::pair<int*, int> DeserializeIntArray(int index)
		{
			std::pair<int*, int> pair; // Making pair
			pair.second = DeserializeInt(index); // getting size of array
			const auto array = new int[pair.second]; // Creating array on heap
			pair.first = array; // Setting the array as the first element
			for (int i = sizeof(int); i < pair.second * sizeof(int) + sizeof(int); i+=sizeof(int))
				array[i / sizeof(int) - 1] = DeserializeInt(index + i); // Filling the array
			return pair;
		}

		std::pair<bool*, int> DeserializeBoolArray(int index)
		{
			std::pair<bool*, int> pair; // Making pair
			pair.second = DeserializeInt(index); // getting size of array
			auto array = new bool[pair.second]; // Creating array on heap
			pair.first = array; // Setting the array as the first element
			for (int i = sizeof(int); i < pair.second * sizeof(bool) + sizeof(int); i+=sizeof(bool))
				array[i / sizeof(bool) - 1] = DeserializeInt(index + i); // Filling the array
			return pair;
		}
		
		std::pair<char*, int> DeserializeCharArray(int index)
		{
			std::pair<char*, int> pair; // Making pair
			pair.second = DeserializeInt(index); // getting size of array
			const auto array = new char[pair.second]; // Creating array on heap
			pair.first = array; // Setting the array as the first element
			for (int i = sizeof(int); i < pair.second * sizeof(char) + sizeof(int); i+=sizeof(char))
				array[i / sizeof(char) - 1] = DeserializeInt(index + i); // Filling the array
			return pair;
		}

		std::pair<wchar_t*, int> DeserializeWcharArray(int index)
		{
			std::pair<wchar_t*, int> pair; // Making pair
			pair.second = DeserializeInt(index); // getting size of array
			const auto array = new wchar_t[pair.second]; // Creating array on heap
			pair.first = array; // Setting the array as the first element
			for (int i = sizeof(int); i < pair.second * sizeof(wchar_t) + sizeof(int); i+=sizeof(wchar_t))
				array[i / sizeof(wchar_t) - 1] = DeserializeInt(index + i); // Filling the array
			return pair;
		}

		std::pair<float*, int> DeserializeFloatArray(int index)
		{
			std::pair<float*, int> pair; // Making pair
			pair.second = DeserializeInt(index); // getting size of array
			const auto array = new float[pair.second]; // Creating array on heap
			pair.first = array; // Setting the array as the first element
			for (int i = sizeof(int); i < pair.second * sizeof(float) + sizeof(int); i+=sizeof(float))
				array[i / sizeof(float) - 1] = DeserializeInt(index + i); // Filling the array
			return pair;
		}

		std::pair<double*, int> DeserializeDoubleArray(int index)
		{
			std::pair<double*, int> pair; // Making pair
			pair.second = DeserializeInt(index); // getting size of array
			const auto array = new double[pair.second]; // Creating array on heap
			pair.first = array; // Setting the array as the first element
			for (int i = sizeof(int); i < pair.second * sizeof(double) + sizeof(int); i+=sizeof(double))
				array[i / sizeof(double) - 1] = DeserializeInt(index + i); // Filling the array
			return pair;
		}
	};
}
