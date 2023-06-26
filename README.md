# Braccio Observer
A C++ Arduino script that monitors the serial port for instructions on how to control the Arduino or Braccio robot arm.

## Communication Protocol

### Instruction Format


### Commands
| Command        | Description                                               | Letter |
|----------------|-----------------------------------------------------------|:------:|
| SETUP          | Moves the Arduino into the default position.              |   S    |
| ROTATE         | Tell the robot arm to rotate (`ROTATE [MOTOR] [DEGREES]`) |   R    |

### Constants
| Constants | Description                                                                    | Number |
|-----------|--------------------------------------------------------------------------------|:------:|
| M1        | Reference the M1 motor when rotating.                                          |   1    |
| M2        | Reference the M2 motor when rotating.                                          |   2    |
| M3        | Reference the M3 motor when rotating.                                          |   3    |
| M4        | Reference the M4 motor when rotating.                                          |   4    |
| M5        | Reference the M5 motor when rotating.                                          |   5    |
| M6        | Reference the M6 motor when rotating.                                          |   6    |
| DEFAULT   | Reference the default motor position (returns motor to its original position). |  999   |

## Related Projects
- [Robot Arm Controller - Proof of concept](https://github.com/hrszpuk/BraccioProofOfConcept)
- [Robot Arm Controller (frontend)](https://github.com/hrszpuk/BraccioController)

