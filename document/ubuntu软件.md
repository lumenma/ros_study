截屏录屏软件

```
https://blog.csdn.net/weixin_40153532/article/details/79337630?utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control
```

jietu

```
cd /home/***/opencv/build
sudo make uninstall
cd  ..
sudo rm -r build

sudo rm -r /usr/local/include/opencv2 /usr/local/include/opencv /usr/include/opencv /usr/include/opencv2 /usr/local/share/opencv /usr/local/share/OpenCV /usr/share/opencv /usr/share/OpenCV /usr/local/bin/opencv* /usr/local/lib/libopencv*
cd /usr
find . -name "*opencv*" | xargs sudo rm -rf
cd /home/lumenma
chmod a+x /home/lumenma/opencv
rm -r /home/lumenma/opencv

sudo apt-get installbuild-essential 
sudo apt-get install cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev
sudo apt-get install python-dev python-numpy libtbb2 libtbb-dev libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev

export PKG_CONFIG_PATH="/usr/local/opencv4/lib/pkgconfig:$PKG_CONFIG_PATH"
export LD_LIBRARY_PATH="/usr/local/opencv4/lib:$LD_LIBRARY_PATH"

https://blog.csdn.net/echoamor/article/details/83022352?utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7EBlogCommendFromMachineLearnPai2%7Edefault-1.control

https://www.it610.com/article/1274486110382211072.htm

https://blog.csdn.net/weixin_43436587/article/details/107622477?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522162847145016780262542616%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=162847145016780262542616&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~times_rank-3-107622477.first_rank_v2_pc_rank_v29&utm_term=ubuntu16.04+opencv&spm=1018.2226.3001.4187
curl "https://bootstrap.pypa.io/pip/3.5/get-pip.py" -o "get-pip.py"

a = cv2.imread("/home/lumenma/1.png ")
/home/lumenma/1.png

Ubuntu 18.10 下实现一键截图文字识别功能Ubuntu 18.10 下实现一键截图文字识别功能
https://docs.qq.com/doc/DWGtmV1RuSG9IY0V6
sudo add-apt-repository ppa:alex-p/tesseract-ocr
sudo apt-get update
sudo apt-get install tesseract-ocr
sudo apt-get install gnome-screenshot
sudo apt-get install xclip
sudo apt-get install imagemagick
/usr/share/tesseract-ocr/tessdata/
sudo cp -i chi1.traineddata /usr/share/tesseract-ocr/tessdata/
/home/lumenma/图片/OCR.sh
```

