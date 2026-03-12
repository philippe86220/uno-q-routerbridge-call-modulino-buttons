from arduino.app_utils import App, Bridge
import datetime

def get_system_time():

    now = datetime.datetime.now()

    return now.strftime("%Y-%m-%d %H:%M:%S")


if __name__ == "__main__":

    Bridge.provide("get_system_time", get_system_time)

    App.run()
