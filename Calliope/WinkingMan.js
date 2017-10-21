let SoundInp = 0
let Animate = 0
input.onButtonPressed(Button.A, () => {
    Animate = 1
})
basic.forever(() => {
    for (let i = 0; i < 1000; i++) {
        SoundInp = pins.analogReadPin(AnalogPin.MIC)
        if (SoundInp < 350 || SoundInp > 650) {
            Animate = 1
        }
    }
    if (Animate == 1) {
        basic.showLeds(`
            . . . . .
            . # . # .
            . . . . .
            # . . . #
            . # # # .
            `)
        pins.servoWritePin(AnalogPin.P1, 45)
        basic.pause(500)
        pins.servoWritePin(AnalogPin.P1, 135)
        basic.pause(500)
        pins.servoWritePin(AnalogPin.P1, 90)
        basic.pause(500)
        basic.showLeds(`
            . # . # .
            . . . . .
            . . . . .
            . # # # .
            # . . . #
            `)
        Animate = 0
    }
})
pins.servoWritePin(AnalogPin.P1, 90)
Animate = 1
