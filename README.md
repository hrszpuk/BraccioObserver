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
| ROTATE         | Tell the robot arm to rotate  |   `RMDDD...`    |
| START_RECORD   | Starts recording all instructions being written (can be played back) | `SIII` |
| END_RECORD     | Ends the recording `III` is the numerical ID representing that recording | `EIII` |
| PLAY_RECORD    | Plays back a record with the ID `III` | `PIII` |
| DEFAULT_POS    | Moves all the motors into a starting position | `D` |
| SET_DEFAULT_POS | Sets the default position for motors to be moved into | `TMDDD...` |

### Parsing Instruction Format
Each instruction need to be parsed differently.
However, many instructions can be parsed in a similar way that helps us.

There are 2 distinct parsers that can be used.
Firstly, instructions that *can* reach the 25 byte capacity and follow the IMDDD pattern (Instruction Byte, Motor Byte, Degrees Bytes).
Secondly, instructions that follow a IXXX pattern (Instruction Byte, ID Bytes).
Finally, there is a instruction that is only a single byte (Default Instruction), in this case we can just read the instruction byte.

### Arduino Response
The Arduino will send a response for each instruction recieved.
It will send an immidiate response indicating it has recieved an instruction, and it will send another response indicating whether an insturction has passed or failed.

## Related Projects
- [Robot Arm Controller - Proof of concept](https://github.com/hrszpuk/BraccioProofOfConcept)
- [Robot Arm Controller (frontend)](https://github.com/hrszpuk/BraccioController)

