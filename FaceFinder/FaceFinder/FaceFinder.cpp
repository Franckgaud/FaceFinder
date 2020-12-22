#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

int main( )
{

    CascadeClassifier face_cascade;
    face_cascade.load("Resources/haarcascade_frontalface_alt2.xml");
    if (!face_cascade.load("Resources/haarcascade_frontalface_alt2.xml"))
    {
        cerr << "Error Loading XML file" << endl;
        return 0;
    }

 VideoCapture capture(0);  
    for (;;)
     { 
       Mat image; 
       capture >> image;  
       if (image.empty())  
       break; 

 
 
      std::vector<Rect> faces;
      face_cascade.detectMultiScale( image, faces, 1.1, 2, 0| CASCADE_SCALE_IMAGE, Size(30, 30) );
  
      for( int i = 0; i < faces.size(); i++ )
      {
        Point top(faces[i].x + faces[i].width, faces[i].y + faces[i].height * 0.5);
        Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
        ellipse( image, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 0, 255, 0 ), 4, 8, 0 );
        putText(image, "No MASK", top, FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 0, 255), 2);
            
      }
      
  imshow( "Detected Face", image );
  waitKey(1);  
   }  
               
     return 0;
}