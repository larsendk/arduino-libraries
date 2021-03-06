arduino-libraries
=================

C++ libraries for running on Arduino hardware.

##Install Arduino on your Host Machine

####Download the Arduino Software

<http://arduino.cc/en/main/software>

####Linux Install

```shell
mkdir ~/arduino
mv ~/Downloads/arduino-X.Y.Z-linuxXX.tar.xz ~/arduino/
cd ~/arduino/
tar -xf arduino-X.Y.Z-linuxXX.tar.xz
```

On linux, you may need to add yourself to the group 'dialout' in order
to have write permissions on the USB port:

```shell
sudo usermod -aG dialout $USER
```

##Install These Arduino Libraries on your Host Machine

###Linux or Mac OS X

Install Python and git on your system if necessary.

[Setup Python and Git for Linux](./PYTHON_GIT_SETUP_LINUX.md)

[Setup Python and Git for Mac OS X](./PYTHON_GIT_SETUP_MAC_OS_X.md)

Open terminal:

```shell
mkdir ~/git
cd ~/git
git clone https://github.com/JaneliaSciComp/arduino-libraries.git
cd arduino-libraries
git submodule init
git submodule update
python symlinks.py --install
```

###Windows

Install git if necessary.

[Setup Git for Windows](./GIT_SETUP_WINDOWS.md)

Open Git Bash:

(Use "Insert" key to paste into Git Bash)

```shell
cd ~/My\ Documents/Arduino
mv libraries/ libraries2/
git clone https://github.com/JaneliaSciComp/arduino-libraries.git libraries
cd libraries
git submodule init
git submodule update
cd ..
cp -r libraries2/. libraries/
cd libraries
git checkout .
```

###Running on Linux

```shell
cd ~/arduino/arduino-X.Y.Z/
./arduino
```

###Linux Setup

```shell
# after Arduino starts, go to File : Preferences
# set Sketchbook location:
# /home/<yourusername>/sketchbook/
```
