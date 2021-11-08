#pragma once
class cmpkt
{
public:
    static void Save(const std::string& binary, const std::string& filename)
    {
        std::cout << filename << ": " << binary << std::endl;
    }

    // TODO make functions for serializing primitive types
    template<typename T>
	static std::string serialize_primitives(T primitive)
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
	    case 12:
			result += *(char*)&primitive;
			result += ((char*)&primitive)[1];
			result += ((char*)&primitive)[2];
			result += ((char*)&primitive)[3];
			result += ((char*)&primitive)[4];
			result += ((char*)&primitive)[5];
			result += ((char*)&primitive)[6];
			result += ((char*)&primitive)[7];
			result += ((char*)&primitive)[8];
			result += ((char*)&primitive)[9];
			result += ((char*)&primitive)[10];
			result += ((char*)&primitive)[11];
			break;
		default: break;
	    }

		return result;
    }
};
