#include <iostream>
#include <windows.h>

#pragma comment(lib,"user32")
#define GetKey(X) (!!(GetAsyncKeyState(0[#X])&0x8000))

using namespace std;

enum class State {
  STANDING,
  DUCKING,
  JUMPING,
  DIVING
};

class StateMachine {
private:
  State currentState;

public:
  StateMachine() : currentState(State::STANDING) {}

  void TransitionsStateMachine() {
    if (currentState == State::STANDING) 
    {
      if (GetKey(A)) 
      {
        currentState = State::DUCKING;
      }
      else if(GetKey(B))
      {
        currentState = State::JUMPING;
      }
    }
    else if(currentState == State::DUCKING) 
    {
      if (!GetKey(A)) 
      {
        currentState = State::STANDING;
      }
    }
    else if (currentState == State::JUMPING) 
    {
      if (GetKey(B)) 
      {
        currentState = State::DIVING;
      }
    }
  }

  void PrintStates() {
    switch (currentState) {
    case State::STANDING: 
      cout << "Standing" << endl; 
      break;
    case State::DUCKING: 
      cout << "Ducking" << endl;
      break;
    case State::JUMPING: 
      cout << "Jumping" << endl;
      break;
    case State::DIVING: 
      cout << "Diving" << endl;
      break;
    }
  }
};

int main() {
  StateMachine sm;

  while (true) {
    sm.TransitionsStateMachine();
    sm.PrintStates();
    Sleep(100);
  }

  return 0;
}
