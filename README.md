# Hear Wi-Fi Like Dial-up

After more than three decades, AOL finally discontinued their dial-up internet service. But now your Wi-Fi connection can make the same beeps, whistles, and hisses.

![](https://raw.githubusercontent.com/nickbild/wifi_dialup/refs/heads/main/media/logo.jpg)

Dropping dial-up internet access may not be big news in 2025 because a 56K connection isn’t fast enough to do much of anything anymore. But even still, it’s a little bit sad. It’s officially the end of an era. Never again will a teenager have to tell their parents to stay off the phone so they can play *Doom* with their friend down the street. And never again will we actually *hear* our internet traffic.

## What's That Sound?

Before we had cable modems or fiber optics in the home, and way before high-bandwidth wireless data was available, the best connection most people had to the outside world was a telephone line. It wasn’t a particularly good option, but it could connect you to nearly any destination in the world.

There was a pretty big problem, however. Computers speak a digital language, while the telephone network was built to transmit analog signals. Without swapping out some hardware (as was done with DSL lines), transmitting digital data would have been unreliable. As a workaround, modems were developed.

Modems convert digital data into analog signals compatible with the existing telephone infrastructure, and vice versa, to send and receive data. And those analog signals are treated just like a voice call by telephones, so they can be heard as sound.

## How It Works

![](https://raw.githubusercontent.com/nickbild/wifi_dialup/refs/heads/main/media/device_sm.jpg)

I wanted to bring the experience of hearing an internet connection into the modern age. I’m using a Raspberry Pi 3 to make that possible. It has a secondary USB Wi-Fi adapter that I use to sniff network traffic. I put the adapter into a mode that receives all traffic, then I filter it to target one particular computer (by following [these steps](https://github.com/nickbild/wifi_dialup/blob/main/monitor.sh)), so that I can focus on its traffic.

I then send the data from the captured packets to an Adafruit QT Py microcontroller via a serial connection. A [Python script](https://github.com/nickbild/wifi_dialup/blob/main/wifi_dialup.py) automates capturing packets and forwarding them to the microcontroller. The microcontroller then turns the received data value into an amplitude that I use to generate a sound wave. This is converted into an analog signal with the onboard digital-to-analog converter, and the output is fed into an audio amplifier that plays the sound through a speaker.

Now, the data is pretty much random, so as you might expect, it sounds basically like static. That’s actually also true of dial-up modems. But wait, what about the connection sounds we all know and love, you ask? Those are special because during the initial handshake, the transfer rate is slowed down and specific steps are always taken. But when real data is transferred, and the speaker turns off, it’s all static.

Wi-Fi connections don't do this dial-up handshake, so to make the Wi-Fi sound more interesting, I make some occasional random adjustments to the amplitude and frequency of the sound wave the device produces, but it is all driven by the Wi-Fi data.

## Bill of Materials

- 1 x Raspberry Pi 3 B+
- 1 x Adafruit QT Py
- 1 x Adafruit Mono 2.5W Class D Audio Amplifier
- 1 x USB Wi-Fi adapter
- 1 x 8 ohm, 2 watt speaker

## About the Author

[Nick A. Bild, MS](https://nickbild79.firebaseapp.com/#!/)