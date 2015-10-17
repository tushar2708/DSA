// Opens an image, converts it to grayscale, and then saves it to another file

#include <opencv2/core/core.hpp>                                                                                                                
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.h>

using namespace cv;

int main( int argc, char** argv )
{
	char* imageName = argv[1];

	if( argc != 2 )
	{
		printf( " No image data \n " );
		return -1;
	}

	Mat image;
	image = imread( imageName, 1 );

	if(! image.data )                              // Check for invalid input
	{
		printf( "Could not open or find the image" );
		return -1;
	}

	Mat gray_image;
	cvtColor( image, gray_image, CV_BGR2GRAY );

	char outputFile[50]={'\0',};
	std::sprintf(outputFile, "Gray_%s",imageName);

	imwrite( outputFile, gray_image );

	namedWindow( imageName, CV_WINDOW_AUTOSIZE );
	namedWindow( outputFile, CV_WINDOW_AUTOSIZE );

	imshow( imageName, image );
	imshow( outputFile, gray_image );

	waitKey(0);

	return 0;
}
