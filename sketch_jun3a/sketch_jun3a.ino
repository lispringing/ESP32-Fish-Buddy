#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// 引脚定义
#define TFT_CS    6
#define TFT_RST   4
#define TFT_DC    5
#define TFT_SCLK  36
#define TFT_MOSI  35
#define TFT_BL    7

// 实例化屏幕
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup(void) {
  Serial.begin(115200);
  // 背光开启
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  // 初始化ST7735黑底屏 128*160
  tft.initR(INITR_REDTAB);

  tft.fillScreen(ST77XX_BLACK);    // 清屏黑色
  tft.setRotation(1);              // 1=横屏；0竖屏、2倒置、3倒置横屏

  // 显示内容
  tft.setTextSize(2);
  tft.setTextColor(ST77XX_WHITE);
  tft.setCursor(10, 20);
  tft.println("ESP32-S3");

  tft.setTextColor(ST77XX_GREEN);
  tft.setCursor(10, 60);
  tft.println("ST7735 1.8TFT");

  tft.setTextColor(ST77XX_RED);
  tft.setCursor(10, 100);
  tft.println("Smart Bath");

  // 画矩形
  tft.drawRect(5, 130, 150, 25, ST77XX_BLUE);
}

void loop(void) {
}