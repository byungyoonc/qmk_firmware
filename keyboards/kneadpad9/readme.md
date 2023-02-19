# Kneadpad9

![kneadpad9](https://i.imgur.com/W2crlcq.jpg)

The first project of Meow Electronics.
3x3 directly connected macropad.

* Keyboard Maintainer: [Choi Byungyoon](https://github.com/Choi Byungyoon)
* Hardware Availability: Available open-sourced at https://github.com/byungyoonc/kneadpad9

Make example for this keyboard (after setting up your build environment):

    make kneadpad9:default

Flashing example for this keyboard:

    make kneadpad9:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Quickly double press the button on the back of the PCB
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
