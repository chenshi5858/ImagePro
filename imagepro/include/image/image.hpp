/**
 * Class Image
 */

#include <string>
#include "image/listofregion.hpp"

namespace image {
	class Image; 
	typedef unsigned char uchar;
	

	class Image{
	private:
		int width;
		int height;
		int th_value;
		uchar* data;
	public:
		Image();
		Image(int w, int h);
		Image(int w, int h, uchar* _data);
		void threshold(); 
    	int getValue(int row, int col);
		void show();
		ListOfRegion* getRegions();
        virtual ~Image(); 
		static Image* readImage(std::string &path);        
	};
}
