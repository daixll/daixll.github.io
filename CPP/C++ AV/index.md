---
html:
    toc: true   # 打开侧边目录
export_on_save:
    html: true  # 自动保存
---

# 引子

[影视飓风将停止制作25帧视频（影视飓风）](https://www.bilibili.com/video/BV1hp4y1f7B5/)
[奇妙的帧率增加了！（影视飓风）](https://www.bilibili.com/video/BV1kE411c7yZ/)
[“视频”是怎么来的？H.264、码率这些词又是什么意思？（极客湾）](https://www.bilibili.com/video/BV1nt411Q7S6/)
[为什么要编码](https://juejin.cn/post/6945838292017840135#heading-3)

[OpenCV 入门教程](https://vincentqin.gitee.io/blogresource-2/cv-books/OpenCV-Guide-Primer.pdf)
[FFmpeg 视频处理入门教程（使用，非开发）](https://www.ruanyifeng.com/blog/2020/01/ffmpeg.html)
[FFMPEG开发快速入坑——绪论](https://zhuanlan.zhihu.com/p/345402619)
[雷霄骅的开源视音频项目汇总](https://blog.csdn.net/leixiaohua1020/article/details/42658139)

<br>

---


# 音频编码

* MP3

* AAC

* FLAC

<br>

---

# 视频编码

* H.264

* H.265

<br>

---

# 音视频封装

* mp4

* ts

* flv

* mkv

<br>

---

# 音视频传输

* RTP

* RTCP

* SRT

<br>

---

# V4L2



<br>

---


# OpenCV

## 安装



1. 安装
    **Linux**
    
    * `apt install libopencv-dev`

    **Windows**
    
    1. 下载
    2. 安装

2. 测试

    **Linux**
    
    ```cpp
    #include <opencv2/opencv.hpp>
    #include <iostream>

    using namespace cv;
    using namespace std;

    int main() {
        // 读取图像文件
        Mat image = imread("example.jpg", IMREAD_COLOR);

        // 检查图像是否成功读取
        if(image.empty()) {
            cout << "无法读取图像文件" << endl;
            return -1;
        }

        // 在窗口中显示图像
        imshow("Image", image);
        waitKey(0);

        return 0;
    }
    ```

    ```
    g++ main.cpp -o main `pkg-config --cflags --libs opencv4`
    ```

<br>

---

# FFmpeg

## 安装

1. 安装
    **Linux**
    `sudo apt install ffmpeg libavcodec-dev libavformat-dev libavutil-dev libswscale-dev`

2. 测试
    ```cpp
    extern "C"{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libavutil/dict.h>
    }

    int main(int argc, char *argv[]) {
        avformat_network_init(); // 替换 av_register_all()

        AVFormatContext *formatContext = NULL;

        // 打开视频文件
        if (avformat_open_input(&formatContext, argv[1], NULL, NULL) !=     0) {
            fprintf(stderr, "无法打开视频文件\n");
            return -1;
        }

        // 获取视频文件信息
        if (avformat_find_stream_info(formatContext, NULL) < 0) {
            fprintf(stderr, "无法获取视频文件信息\n");
            return -1;
        }

        // 打印视频文件信息
        av_dump_format(formatContext, 0, argv[1], 0);

        // 关闭视频文件
        avformat_close_input(&formatContext);

        return 0;
    }
    ```
    ```
    g++ main.cpp -o main -lavcodec -lavformat -lavutil -lswscale
    ```