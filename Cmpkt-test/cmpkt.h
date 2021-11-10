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
			for (int i = 4; i < pair.second * 4 + 4; i+=4)
				array[i / 4 - 1] = DeserializeInt(index + i); // Filling the array
			return pair;
		}

		std::pair<bool*, int> DeserializeBoolArray(int index)
		{
			std::pair<bool*, int> pair; // Making pair
			pair.second = DeserializeInt(index); // getting size of array
			auto array = new bool[pair.second]; // Creating array on heap
			pair.first = array; // Setting the array as the first element
			for (int i = 4; i < pair.second + 4; i++)
				array[i - 1] = DeserializeBool(index + i); // Filling the array
			return pair;
		}
		
		std::pair<char*, int> DeserializeCharArray(int index)
		{
			std::pair<char*, int> pair; // Making pair
			pair.second = DeserializeInt(index); // getting size of array
			const auto array = new char[pair.second]; // Creating array on heap
			pair.first = array; // Setting the array as the first element
			for (int i = 4; i < pair.second + 4; i++)
				array[i - 1] = DeserializeInt(index + i); // Filling the array
			return pair;
		}

		std::pair<wchar_t*, int> DeserializeWcharArray(int index)
		{
			std::pair<wchar_t*, int> pair; // Making pair
			pair.second = DeserializeInt(index); // getting size of array
			const auto array = new wchar_t[pair.second]; // Creating array on heap
			pair.first = array; // Setting the array as the first element
			for (int i = 4; i < pair.second * 2 + 4; i+=2)
				array[i / 2 - 1] = DeserializeInt(index + i); // Filling the array
			return pair;
		}

		std::pair<float*, int> DeserializeFloatArray(int index)
		{
			std::pair<float*, int> pair; // Making pair
			pair.second = DeserializeInt(index); // getting size of array
			const auto array = new float[pair.second]; // Creating array on heap
			pair.first = array; // Setting the array as the first element
			for (int i = 4; i < pair.second * 4 + 4; i+=4)
				array[i / 4 - 1] = DeserializeInt(index + i); // Filling the array
			return pair;
		}

		std::pair<double*, int> DeserializeDoubleArray(int index)
		{
			std::pair<double*, int> pair; // Making pair
			pair.second = DeserializeInt(index); // getting size of array
			const auto array = new double[pair.second]; // Creating array on heap
			pair.first = array; // Setting the array as the first element
			for (int i = 4; i < pair.second * 8 + 4; i+=8)
				array[i / 8 - 1] = DeserializeInt(index + i); // Filling the array
			return pair;
		}
	};
}
