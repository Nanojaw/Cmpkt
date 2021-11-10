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
	    for (int i = 0; i < size; i++)
	    {
		    result += Serialize_Primitives(array[i]);
	    }
    	return result;
    }

	class Deserializer
	{
	public:
		std::string Serialized;

		explicit Deserializer(const std::string& serialized) : Serialized(serialized) {}

		int DeserializeInt(int index) { return *(int*)&Serialized[index]; }
		int DeserializeBool(int index) { return *(bool*)&Serialized[index]; }
		int DeserializeChar(int index) { return Serialized[index]; }
		int DeserializeWchar(int index) { return *(wchar_t*)&Serialized[index]; }
		int DeserializeFloat(int index) { return *(float*)&Serialized[index]; }
		int DeserializeDouble(int index) { return *(double*)&Serialized[index]; }
	};
}
