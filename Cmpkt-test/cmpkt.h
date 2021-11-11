#pragma once
#include <vector>
#include <fstream>

namespace cmpkt
{
	inline void Save(const std::string& data, const std::string& filename)
    {
		std::ofstream file(filename.c_str());
		file << data;
		file.close();
    }

	inline std::string Load(const std::string& filename)
	{
		std::ifstream file(filename.c_str());

		if(!file.is_open()) return std::string();

		return std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());
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

		std::vector<int> DeserializeIntArray(int index)
		{
			const int length = DeserializeInt(index); // Getting size of array
			std::vector<int> vector;
			vector.reserve(length);
			for (int i = sizeof(int); i < length * sizeof(int) + sizeof(int); i+=sizeof(int))
				vector.push_back(DeserializeInt(index + i)); // Filling the array
			return vector;
		}

		std::vector<bool> DeserializeBoolArray(int index)
		{
			const int length = DeserializeInt(index); // Getting size of array
			std::vector<bool> vector;
			vector.reserve(length);
			for (int i = sizeof(int); i < length * sizeof(bool) + sizeof(int); i+=sizeof(bool))
				vector.push_back(DeserializeBool(index + i)); // Filling the array
			return vector;
		}
		
		std::vector<char> DeserializeCharArray(int index)
		{
			const int length = DeserializeInt(index); // Getting size of array
			std::vector<char> vector;
			vector.reserve(length);
			for (int i = sizeof(int); i < length * sizeof(char) + sizeof(int); i+=sizeof(char))
				vector.push_back(DeserializeChar(index + i)); // Filling the array
			return vector;
		}

		std::vector<wchar_t> DeserializeWcharArray(int index)
		{
			const int length = DeserializeInt(index); // Getting size of array
			std::vector<wchar_t> vector;
			vector.reserve(length);
			for (int i = sizeof(int); i < length * sizeof(wchar_t) + sizeof(int); i+=sizeof(wchar_t))
				vector.push_back(DeserializeWchar(index + i)); // Filling the array
			return vector;
		}

		std::vector<float> DeserializeFloatArray(int index)
		{
			const int length = DeserializeInt(index); // Getting size of array
			std::vector<float> vector;
			vector.reserve(length);
			for (int i = sizeof(int); i < length * sizeof(float) + sizeof(int); i+=sizeof(float))
				vector.push_back(DeserializeFloat(index + i)); // Filling the array
			return vector;
		}

		std::vector<double> DeserializeDoubleArray(int index)
		{
			const int length = DeserializeInt(index); // Getting size of array
			std::vector<double> vector;
			vector.reserve(length);
			for (int i = sizeof(int); i < length * sizeof(double) + sizeof(int); i+=sizeof(double))
				vector.push_back(DeserializeDouble(index + i)); // Filling the array
			return vector;
		}
	};
}
