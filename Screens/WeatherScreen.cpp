
#include "WeatherScreen.h"

#include "OptimaLTStd12pt7b.h"
#include "TimeScreen.h"
#include "BatteryScreen.h"

using namespace Watchy;

static const char *weatherConditionCodeToString(int16_t weatherConditionCode) {
  switch (weatherConditionCode) {
    case 200:
      return "thunderstorm & light rain";
    case 201:
      return "thunderstorm & rain";
    case 202:
      return "thunderstorm & heavy rain";
    case 210:
      return "light thunderstorm";
    case 211:
      return "thunderstorm";
    case 212:
      return "heavy thunderstorm";
    case 221:
      return "ragged thunderstorm";
    case 230:
      return "thunderstorm & light drizzle";
    case 231:
      return "thunderstorm & drizzle";
    case 232:
      return "thunderstorm & heavy drizzle";
    case 300:
      return "light drizzle";
    case 301:
      return "drizzle";
    case 302:
      return "heavy drizzle";
    case 310:
      return "light drizzle rain";
    case 311:
      return "drizzle rain";
    case 312:
      return "heavy drizzle rain";
    case 313:
      return "drizzle & rain showers";
    case 314:
      return "drizzle & heavy rain showers";
    case 321:
      return "drizzle showers";
    case 500:
      return "light rain";
    case 501:
      return "moderate rain";
    case 502:
      return "heavy rain";
    case 503:
      return "very heavy rain";
    case 504:
      return "extreme rain";
    case 511:
      return "freezing rain";
    case 520:
      return "light rain showers";
    case 521:
      return "rain showers";
    case 522:
      return "heavy rain showers";
    case 531:
      return "ragged rain showers";
    case 600:
      return "light snow";
    case 601:
      return "snow";
    case 602:
      return "heavy snow";
    case 611:
      return "sleet";
    case 612:
      return "light sleet showers";
    case 613:
      return "sleet showers";
    case 615:
      return "light rain & snow";
    case 616:
      return "rain & snow";
    case 620:
      return "light snow showers";
    case 621:
      return "snow showers";
    case 622:
      return "heavy snow showers";
    case 701:
      return "mist";
    case 711:
      return "smoke";
    case 721:
      return "haze";
    case 731:
      return "sand/dust whirls";
    case 741:
      return "fog";
    case 751:
      return "sand";
    case 761:
      return "dust";
    case 762:
      return "volcanic ash";
    case 771:
      return "squalls";
    case 781:
      return "tornado";
    case 800:
      return "clear";  // <= 10%
    case 801:
      return "light clouds";  // 11-25%
    case 802:
      return "partly cloudy";  // 26-50%
    case 803:
      return "mostly cloudy";  // 51-80%
    case 804:
      return "cloudy";  // > 80%
    default:
      return "unknown";
  }
}

void WeatherScreen::show() {
  display.setFont(&OptimaLTStd12pt7b);
  display.setTextWrap(true);
  display.setCursor(0, 0);
  weatherData wd = getWeatherData();
  display.printf("\n%d deg\n%s", wd.temperature,
                 weatherConditionCodeToString(wd.weatherConditionCode));
  DEBUG("\n%d deg\n%s\n", wd.temperature,
        weatherConditionCodeToString(wd.weatherConditionCode));
}
