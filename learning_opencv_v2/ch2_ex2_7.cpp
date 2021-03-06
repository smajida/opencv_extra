/* License:
   July 20, 2011
   Standard BSD

   BOOK: It would be nice if you cited it:
   Learning OpenCV 2: Computer Vision with the OpenCV Library
     by Gary Bradski and Adrian Kaehler
     Published by O'Reilly Media
 
   AVAILABLE AT: 
     http://www.amazon.com/Learning-OpenCV-Computer-Vision-Library/dp/0596516134
     Or: http://oreilly.com/catalog/9780596516130/
     ISBN-10: 0596516134 or: ISBN-13: 978-0596516130    

   Main OpenCV site
   http://opencv.willowgarage.com/wiki/
   * An active user group is at:
     http://tech.groups.yahoo.com/group/OpenCV/
   * The minutes of weekly OpenCV development meetings are at:
     http://pr.willowgarage.com/wiki/OpenCV
*/
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>

using namespace cv;
using namespace std;


void help()
{
	cout << "Call: ./ch2_ex2_7 faceScene.jpg" << endl;
}
int main( int argc, char** argv )
{
  Mat img_rgb  = imread( argv[1],-1 );
	help();
	if(img_rgb.empty())
	{
		std::cerr << "Couldn't open the image " << argv[1] << std::endl;
		return -1;
	}
  Mat img_gry, img_pyr, img_pyr2, img_cny;
  cvtColor(img_rgb, img_gry ,CV_BGR2GRAY);
  pyrDown(img_gry,img_pyr);
  pyrDown(img_pyr,img_pyr2);
  Canny(img_pyr2,img_cny,10,100,3,true);
  namedWindow("Example Gray", CV_WINDOW_AUTOSIZE );
  namedWindow("Example Pyr", CV_WINDOW_AUTOSIZE );
  namedWindow("Example Canny", CV_WINDOW_AUTOSIZE );
  imshow("Example Gray", img_gry );
  imshow("Example Pyr", img_pyr2 );
  imshow("Example Canny", img_cny );
  waitKey(0);
}
