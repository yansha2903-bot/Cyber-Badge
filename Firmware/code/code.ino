void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
#include <GxEPD2_BW.h>
#include <Adafruit_GFX.h>

// --- Настройка пинов для XIAO ESP32-C3 ---
#define EPD_BUSY 2 // D0 (GPIO2)
#define EPD_RST 3 // D1 (GPIO3)
#define EPD_DC 4 // D2 (GPIO4)
#define EPD_CS 5 // D3 (GPIO5)
#define EPD_BTN 6 // D4 (GPIO6) - Кнопка переключения

// --- Инициализация дисплея ---
// Пример для популярного 1.54" / 2.13" E-Ink экрана (200x200 или 250x122)
// Если модель экрана отличается, смени класс дисплея (например, GxEPD2_213_B74)
GxEPD2_BW<GxEPD2_154_D67, GxEPD2_154_D67::HEIGHT> display(
GxEPD2_154_D67(EPD_CS, EPD_DC, EPD_RST, EPD_BUSY)
);

// Переменная для хранения текущего экрана/статуса
int currentMode = 0;
const int TOTAL_MODES = 3;

void setup() {
pinMode(EPD_BTN, INPUT_PULLUP); // Кнопка подтянута к 3.3V

// Инициализация экрана
display.init(115200, true, 50, false);

// Поворот экрана (0, 1, 2 или 3 в зависимости от монтажа на плате)
display.setRotation(1);

// Отрисовка первого экрана при включении
drawBadge(currentMode);
}

void loop() {
// Проверяем нажатие на кнопку (сигнал LOW при нажатии)
if (digitalRead(EPD_BTN) == LOW) {
delay(50); // Антидребезг контактов
if (digitalRead(EPD_BTN) == LOW) {

// Переключаем режим
currentMode = (currentMode + 1) % TOTAL_MODES;

// Обновляем изображение на E-Ink экране
drawBadge(currentMode);

// Ждем, пока отпустят кнопку
while (digitalRead(EPD_BTN) == LOW) {
delay(10);
}
}
}

delay(100);
}

// --- Функция отрисовки разных страниц бейджа ---
void drawBadge(int mode) {
display.setFullWindow();
display.firstPage();

do {
display.fillScreen(GxEPD_WHITE);
display.setTextColor(GxEPD_BLACK);

if (mode == 0) {
// Страница 1: Главный бейдж
display.setTextSize(2);
display.setCursor(10, 20);
display.print("HELLO!");

display.setTextSize(1);
display.setCursor(10, 50);
display.print("My name is:");

display.setTextSize(3);
display.setCursor(10, 80);
display.print("MAKER"); // Твое имя / Никнейм

display.setTextSize(1);
display.setCursor(10, 130);
display.print("Hack Club Member");

} else if (mode == 1) {
// Страница 2: Текущий статус
display.setTextSize(2);
display.setCursor(10, 20);
display.print("CURRENT STATUS:");

display.drawRect(10, 50, 180, 50, GxEPD_BLACK); // Рамка
display.setTextSize(2);
display.setCursor(25, 68);
display.print("< CODING... >");

} else if (mode == 2) {
// Страница 3: Контакты / QR место
display.setTextSize(2);
display.setCursor(10, 20);
display.print("FIND ME:");

display.setTextSize(1);
display.setCursor(10, 60);
display.print("GitHub: @your-nick");
display.setCursor(10, 80);
display.print("Discord: @your-nick");

// Декоративная рамка по краю экрана
display.drawRect(0, 0, display.width(), display.height(), GxEPD_BLACK);
}

} while (display.nextPage());

// Переводим экран в режим энергосбережения после обновления
display.powerOff();
}
