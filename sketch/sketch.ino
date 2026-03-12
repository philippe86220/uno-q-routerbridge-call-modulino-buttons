#include <Arduino.h>
#include <Arduino_RouterBridge.h>
#include <Modulino.h>

ModulinoButtons buttons;

void requestTime(const char* buttonName);

void setup() {
  Bridge.begin();
  Monitor.begin();

  Modulino.begin();
  buttons.begin();

  Monitor.println("MCU ready");
}

void loop() {
  if (buttons.update()) {

    if (buttons.isPressed('A')) {
      requestTime("A");
    }

    if (buttons.isPressed('B')) {
      requestTime("B");
    }

    if (buttons.isPressed('C')) {
      requestTime("C");
    }
  }

  delay(20);
}

void requestTime(const char* buttonName) {
  Monitor.println(String("Button ") + buttonName + " pressed");

  String timeString;
  RpcCall rpc = Bridge.call("get_system_time");

  if (rpc.result(timeString)) {
    Monitor.println("Time received from MPU: " + timeString);
  } else {
    Monitor.println("RPC error code: " + String(rpc.getErrorCode()));
    Monitor.println("RPC error message: " + rpc.getErrorMessage());
  }
}
