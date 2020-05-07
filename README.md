# Eight Queens with Linux+Qt+openCV

### Feature

* **manually select the initial position of chess by mouse.**
* **obtain image from camera.**
* **location of the chess board using AprilTags.**
* **binary image processing for chess position.**
* **update chess location automatically.**
* **figure out the closest solution of Eight Queens game.**



### **notes:**

* This is my curriculum project of Linux system. Feel free to check and modify it.
* This repository includes the Qt project of the whole work. As you may konw, you have to do more than it before you can run it up. you must have finished the following part at least:
  * Setup you Linux env and Qt env correctly.
  * use correct CMake tool and set it as cross platform complier.
  * Cross complie the openCV  source and add the lib files in Linux env(on Linux board and PC).
  * complie Qt project with Cmake tool in PC (dont run the executive file).
  * load and run the  executive file in Linux board.
* FOR this project, the camera is operated by library V4L2.
* openCV using with Apriltag complie needs paticular version of Cmake.
* the Linux board is NXP iMX 6Q.
* detailed description in [CSDN](https://blog.csdn.net/weixin_40472289/article/details/102295718).



# Features description

### Hardware

<div align="center">
    <img src=".\PNG\imx.jpg" alt="imx" height="200" />
    <img src=".\PNG\camera.jpg" alt="camera" height="200" />
     <img src=".\PNG\mapofcar.png" alt="mapofcar" height="200" />
</div>

* The screen shown below and power circuit not included.

* There is serial port connection with PC.



### Coding platform

Here shows the env, Qtdesigner while coding and the code files.

<div align="center">
    <img src=".\PNG\lib.png" alt="lib" height="200" />
    <img src=".\PNG\desigener.png" alt="desigener" height="200" />
     <img src=".\PNG\class.png" alt="class" height="200" />
</div>

* The .pro file clearly show the opencv env setting and qt file tree.



### System result

Project can work robustly and finish following functions:

* manually select the initial position of chess by mouse.
* obtain image from camera.
* location of the chess board using AprilTags.
* binary image processing for chess position.
* update chess location automatically.
* figure out the closest solution of Eight Queens game.



<div align="center">
    <img src=".\PNG\chess.png" alt="chess" height="140" />
 <img src=".\PNG\cameca_catch.jpg" alt="cameca_catch" height="140" />
 <img src=".\PNG\recorusult.jpg" alt="recorusult" height=140" />
</div>

### 
### 

**Please feel free to contact me if any question arises. I am warmhearted to communicate and improve it.**

---



### update

* **cross platform information**

  some detailed setting :

  arm-linux-gcc-4.3.2 with openCV 2  

  using cmake  gui set :  **don't** tick : with eigen / with tiff/ opencl

  add lpthread -lrt  to file:CmakeCache.txt,CMAKE_EXE_LINKER_FLAGS

  then make，make install  

  <img src="./PNG/cmake-gui2.png" height="200"/>

  
