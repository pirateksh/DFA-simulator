# DFA-simulator
A command line simulator for <b>_Deterministic Finite Automata_</b> (DFA).

## How to use ?
* Clone this repository into a folder using <b>git clone</b>.
* Open terminal and compile the _dfa.cpp_ file. (in Linux terminal use, <b>g++ dfa.cpp</b> to compile).
* Run the generated _a.out_ file using <b>./a.out</b>.
* Firstly, you need to configure the DFA.

## Configuring DFA
* <b>Set of inputs: </b> Firstly, enter number of inputs and then enter all the inputs separated by a space.
* <b>Set of states: </b> You just need to enter total number of states (say n) in your DFA. By default states are numbered from <b>_0_</b> to <b>_n-1_</b>.
* <b>Set of final states: </b> Firstly, enter number of final states and then enter all the final states (remember set of states are numbered from 0 to n-1, so only enter numbers between 0 and n-1 included) present in your DFA.
* <b>Initial State :</b> It is assumed to be 0 by default.
* <b>Transition function :</b> For each state, starting from initial state, and for each input per state, fill the corresponding next states.
* Sit back and relax, your DFA is now configured and ready to be used.

## Testing DFA
* Test inputs can be written in _input.txt_ file separated by a new line character i.e. one input string per line. The configured DFA will automatically test these input strings which are specified in this file.
* If you feel like testing on more inputs after the inputs from a file are exhausted, you can even give input strings from the command line itself.

## Output Format 
* For each input string, the DFA will specify whether the input was <b>Accepted</b>, <b>Rejected</b> or <b>Invalid Input</b>.

## Contributor
* <a href="https://github.com/pirateksh/">Kshitiz Srivastava</a>
