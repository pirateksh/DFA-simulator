/* 
	@author: Kshitiz Srivastava (pirateksh)
*/
#include<bits/stdc++.h>
using namespace std;
// Comment
#define vi vector<int>
#define si set<char>
#define pb(v, x) v.push_back(x)


vector<char> set_of_inputs;
int initial_state = 0;
int number_of_states;
vi set_of_final_states;
vi transition_function[100000];
map<char, int> input_to_index;

void enter_set_of_inputs() {
	int n;
	char input;
	cout << "Enter total number of inputs: ";
	cin >> n;
	cout << "Enter inputs separated by a space: ";
	for(int i = 0; i < n; i++) {
		cin >> input;
		pb(set_of_inputs, input);
		input_to_index[input] = i+1;
	}
	cout << "Set of inputs have been successfully recorded.\n";
}

void enter_total_number_of_states() {
	cout << "Enter total number of states: ";
	cin >> number_of_states;
	cout << "Set of states have been successfully recorded.\n";
}

void enter_set_of_final_states() {
	int n, final_state;
	cout << "Enter total number of final states: ";
	cin >> n;
	cout << "Enter final states separated by a space: ";
	for(int i = 0; i < n; i++) {
		cin >> final_state;
		pb(set_of_final_states, final_state);
	}
	cout << "Set of final states have been successfully recorded.\n";
}

void enter_initial_state() {
	cout << "Initial State is assumed to be 0 by default.\n";
}

void define_transition_function() {
	int number_of_inputs = set_of_inputs.size(), next_state;
	for(int i = 0; i < number_of_states; i++) {
		for(int j = 0; j < number_of_inputs; j++) {
			cout << "Current state: " << i << " Input: " << set_of_inputs[j] << " Enter next state: ";
			cin >> next_state;
			pb(transition_function[i], next_state);
		}
	}
}

void configure_machine() {
	enter_set_of_inputs();
	enter_total_number_of_states();
	enter_set_of_final_states();
	enter_initial_state();
	define_transition_function();
	cout << "Machine has been successfully configured according to your input(s).\nYou can use this machine now\n";
}



void init() {
	cout << "----------------------------------\n";
	cout << " ### Welcome to DFA Simulator ###\n";
	cout << "----------------------------------\n";
}

void check(string s) {
	int current_state = initial_state, i;
	for(i = 0; i < s.length(); i++) {
		if(input_to_index[s[i]] == 0) break;
		current_state = transition_function[current_state][input_to_index[s[i]] - 1];
 	}
 		
 	if(i!=s.length()) {
 		cout << s << " is Invalid Input\n";
 		return;
 	}
 	
	 for(i = 0; i < set_of_final_states.size(); i++) {
	 	if(current_state == set_of_final_states[i]) break;
	 }
	 	
	 if(i == set_of_final_states.size()) cout << s << " is Rejected\n";
	 else cout << s << " is Accepted\n";
	 
}

void test() {
	fstream file; 
    string s, filename; 
    filename = "input.txt"; 
  
    file.open(filename.c_str()); 
  	cout << "Testing on pre-fed inputs from file:\n";
    while (file >> s) { 
        check(s);
    }
    cout << "All inputs from the file have been exhausted.\n";
    file.close();
    int flag;
    cout << "Do you want to test some more inputs ? (enter 1 for Yes): ";
    cin >> flag;
    while(flag==1) {
    	cout << "Enter input string: ";
    	cin >> s;
    	check(s);
    	cout << "Do you want to test some more inputs ? (enter 1 for Yes): ";
    	cin >> flag;
    }

    cout << "Thankyou for using this simulator.\n";
}

int main() {
	init();
	configure_machine();
	test();
	return 0;
}
