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


[FFmpeg 官方文档](https://ffmpeg.org/documentation.html)

[1](https://blog.csdn.net/wanggao_1990/article/details/119207034)

<br>

---

# 音响


<br>

---

# 显示器

## LCD 液晶显示屏

LCD 最底层为光源（通常是 LED 光带），通过 **液晶层** 和色彩滤光片显示出红绿蓝三种颜色

| 液晶层面板 | IPS  | TN | VA |
|:-:|:-:|:-:|:-:|
| 对比度 | - | 低 | 高 |
| 可视角 | 广 | 窄 | - |
| 响应速度 | - | 快 | 慢 |

**Fast IPS**：更快的 IPS 面板
**QLED**：背板射蓝光，加 **量子点膜**，拥有更好的色彩
**mini-LED**：背光分区，对比度上升 | 缺点：背光拖尾

## OLED 有机发光二极管

生物材料，像素级发光 | 缺点：红绿蓝寿命不统一，易老化

**W-OLED** RGBW，加了白光，使寿命统一 | 缺点：色彩下降

**QD-OLED** 使用量子点膜，寿命统一 | 缺点：受光线影响大

## Micro-LED 无机发光二极管

牛逼就完了

## 色域/色准

**sRGB**

最常见的

**DCI-P3**

电影工作室搞得，苹果喜欢用

**AdobeRGB**

123

**xxx% 色域覆盖**

能够达到某色域中定义的xxx%颜色

**ΔE**

* 平均ΔE

* 最大ΔE

## 亮度/对比度/HDR

## 分辨率/刷新率/响应时间

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

v4l2-ctl -d 0 --list-formats-ext

<br>

---


# OpenCV

## 安装

1. 安装
    **Linux**
    
    * `sudo apt install libopencv-dev`

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

## 调用摄像头

```cpp
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
 
int main()
{
	VideoCapture capture(0, cv::CAP_V4L2);
    
    // 设置格式
    capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
    // capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('H', '2', '6', '4'));
    // capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('H', 'E', 'V', 'C'));
    // capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('X', 'V', 'I', 'D'));

    // 设置摄像头的分辨率
    capture.set(cv::CAP_PROP_FRAME_WIDTH, 1920);
    capture.set(cv::CAP_PROP_FRAME_HEIGHT, 1080);
    capture.set(cv::CAP_PROP_FPS, 30);

    // 查询摄像头的参数信息
    double fps = capture.get(cv::CAP_PROP_FPS);
    int width = capture.get(cv::CAP_PROP_FRAME_WIDTH);
    int height = capture.get(cv::CAP_PROP_FRAME_HEIGHT);

    // 输出参数信息
    std::cout << "Frame rate: " << fps << " fps" << std::endl;
    std::cout << "Frame size: " << width << "x" << height << std::endl;

	while (true)
	{
		Mat frame;
		capture >> frame;
		imshow("camera", frame);
		waitKey(1);
	}
    
	return 0;
}
```


<br>

---

# FFmpeg

## 安装

1. 安装
    **Linux**
    `sudo apt install ffmpeg libavformat-dev libavcodec-dev libavdevice-dev libavutil-dev libswscale-dev`

    * `libavformat-dev` 格式处理库
    * `libavcodec-dev` 编解码库
    * `libswresample` 音频格式转换库
    * `libswscale-dev` 视频格式转换库
        
    * `libavdevice-dev` 设备操作库
        
    * `libavutil-dev` Utility辅助库
    * `libavfilter` 音视频滤镜

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

## 调用麦克风

```cpp
#include <iostream>
extern "C" {
#include <libavdevice/avdevice.h>
#include <libavutil/audio_fifo.h>
}

#define AUDIO_IN_DEVICE "default" // 麦克风设备名
#define SAMPLE_RATE 44100 // 采样率
#define CHANNELS 2 // 声道数
#define SAMPLE_FORMAT AV_SAMPLE_FMT_S16 // 采样格式
#define OUTPUT_FILENAME "output.wav" // 输出文件名

int main() {
    avdevice_register_all(); // 注册设备

    AVInputFormat *inputFormat = av_find_input_format("alsa"); // ALSA是Linux上常用的音频设备接口

    AVFormatContext *formatContext = avformat_alloc_context();
    if (!formatContext) {
        std::cerr << "Failed to allocate format context" << std::endl;
        return -1;
    }

    AVDictionary *options = NULL;
    av_dict_set(&options, "ac", std::to_string(CHANNELS).c_str(), 0); // 设置声道数
    av_dict_set(&options, "ar", std::to_string(SAMPLE_RATE).c_str(), 0); // 设置采样率
    av_dict_set(&options, "sample_fmt", av_get_sample_fmt_name(SAMPLE_FORMAT), 0); // 设置采样格式

    if (avformat_open_input(&formatContext, AUDIO_IN_DEVICE, inputFormat, &options) < 0) {
        std::cerr << "Failed to open audio input device" << std::endl;
        return -1;
    }

    if (avformat_find_stream_info(formatContext, NULL) < 0) {
        std::cerr << "Failed to find stream information" << std::endl;
        return -1;
    }

    AVPacket packet;
    //av_init_packet(&packet);
    av_packet_alloc();

    AVCodec *codec = avcodec_find_encoder(AV_CODEC_ID_PCM_S16LE);
    if (!codec) {
        std::cerr << "Failed to find encoder" << std::endl;
        return -1;
    }

    AVCodecContext *codecContext = avcodec_alloc_context3(codec);
    if (!codecContext) {
        std::cerr << "Failed to allocate codec context" << std::endl;
        return -1;
    }

    codecContext->sample_rate = SAMPLE_RATE;
    codecContext->channels = CHANNELS;
    codecContext->sample_fmt = SAMPLE_FORMAT;

    if (avcodec_open2(codecContext, codec, NULL) < 0) {
        std::cerr << "Failed to open codec" << std::endl;
        return -1;
    }

    AVFormatContext *outputFormatContext = NULL;
    if (avformat_alloc_output_context2(&outputFormatContext, NULL, NULL, OUTPUT_FILENAME) < 0) {
        std::cerr << "Failed to allocate output format context" << std::endl;
        return -1;
    }

    AVStream *outputStream = avformat_new_stream(outputFormatContext, NULL);
    if (!outputStream) {
        std::cerr << "Failed to allocate output stream" << std::endl;
        return -1;
    }

    if (avcodec_parameters_from_context(outputStream->codecpar, codecContext) < 0) {
        std::cerr << "Failed to copy codec parameters to stream" << std::endl;
        return -1;
    }

    if (!(outputFormatContext->oformat->flags & AVFMT_NOFILE)) {
        if (avio_open(&outputFormatContext->pb, OUTPUT_FILENAME, AVIO_FLAG_WRITE) < 0) {
            std::cerr << "Failed to open output file" << std::endl;
            return -1;
        }
    }

    if (avformat_write_header(outputFormatContext, NULL) < 0) {
        std::cerr << "Failed to write header" << std::endl;
        return -1;
    }

    std::cout << "Capturing audio from microphone and saving to " << OUTPUT_FILENAME << " ... Press Ctrl+C to stop." << std::endl;

    while (true) {
        if (av_read_frame(formatContext, &packet) < 0) {
            std::cerr << "Failed to read audio frame" << std::endl;
            break;
        }

        // 写入音频帧到输出文件
        if (av_write_frame(outputFormatContext, &packet) < 0) {
            std::cerr << "Failed to write audio frame" << std::endl;
            break;
        }

        av_packet_unref(&packet); // 释放packet
    }

    av_write_trailer(outputFormatContext);

    avformat_close_input(&formatContext);
    avformat_free_context(formatContext);

    avcodec_close(codecContext);
    avcodec_free_context(&codecContext);

    if (outputFormatContext && !(outputFormatContext->oformat->flags & AVFMT_NOFILE)) {
        avio_closep(&outputFormatContext->pb);
    }
    avformat_free_context(outputFormatContext);

    return 0;
}
```

## 调用摄像头

```cpp

```


## ffplay

```
ffplay -f v4l2 -framerate 30 -video_size 1920x1080 -input_format mjpeg -i /dev/video0 -fflags nobuffer
```