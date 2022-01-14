# What Is OpenGL?
OpenGL is a Graphics rendering API which is operating system independent, window system independent and has high-quality color images composed of geometric and image primitives.   
OpenGL APIs can use following -
- *[GL](http://www.opengl.org)* – OpenGL API implementation 
- *GLU* – OpenGL Utility
- *[Glut (OpenGL Utility Toolkit)](http://www.opengl.org/resources/libraries/glut/)* – Glut is portable windowing API and it is not officially part of OpenGL.  
- *[FLTK (FlashLight ToolKit)](http://www.fltk.org/)*
- *GLEW*  
  
Now lets see how to install OpenGL in Ubuntu.

## Installing OpenGl in Linux

Now because GLUT (OpenGL Utility Toolkit) depends upon OpenGL and a number of other related libraries, if we install GLUT then OpenGL will be automatically be installed.  

First update the repository using the given command  
```$ sudo apt-get update```

Run the following command to install OpenGL.  
```$ sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev```

##  Compile and run c++ program

Now give the command below to compile your code.    
```$ g++ <c++_file_name>.cpp -o <app_name> -lglut -lGLU -lGL```

Now run your OpenGl program with following command  
```$ ./<app_name>```