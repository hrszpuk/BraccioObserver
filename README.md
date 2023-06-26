# Braccio Observer
A C++ Arduino script that monitors the serial port for instructions on how to control the Arduino or Braccio robot arm.

## Communication Protocol

### Instruction Format
The [proof of concept](https://github.com/hrszpuk/BraccioProofOfConcept) used a 5 byte instruction representation.

This project will use a variable length 25 byte capacity instruction representation.
This will allow for *concurrent* motor movement, as well as more information to be parsed in each instruction.




### Commands
| Command        | Description                                               | Pattern |
|----------------|-----------------------------------------------------------|:------:|
| ROTATE         | Tell the robot arm to rotate (`ROTATE [MOTOR] [DEGREES]`) |   `RMDDD...`    |
| START_RECORD   | Starts recording all instructions being written (can be played back) | `SIII` |
| END_RECORD     | Ends the recording `III` is the numerical ID representing that recording | `EIII` |
| PLAY_RECORD    | Plays back a record with the ID `III` | `PIII` |
| DEFAULT_POS    | Moves all the motors into a starting position | `D` |
| SET_DEFAULT_POS | Sets the default position for motors to be moved into | `TMDDD...` |

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

