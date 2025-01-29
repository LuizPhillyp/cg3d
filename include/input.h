#ifndef INPUT_H
#define INPUT_H

#include <cstdint>

#define PRESS = true;
#define RELEASE = false;

#define KEY_DOWN true
#define KEY_UP   false

#define INPUT_STATE_BITSIZE 64
#define STATE_ARRAY_SIZE ((GLFW_KEY_LAST + 1) / INPUT_STATE_BITSIZE + 1)

int64_t keyboardRecordState[STATE_ARRAY_SIZE];
int64_t keyboardState[STATE_ARRAY_SIZE];
int64_t keyStateSwitch[STATE_ARRAY_SIZE];

//CURSOR POSITION
GLfloat screenX, screenY;
GLfloat windowX, windowY;
GLfloat viewportX, viewportY;

//MOUSE BUTTON STATE
GLbyte rmbState;
GLbyte lmbState;

GLbyte rmbRecordState;
GLbyte lmbRecordState;

GLbyte rmbSwitch;
GLbyte lmbSwitch;

//callback para teclas do teclado
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        keyboardState[key / 64] |= (1LL << (key % 64));
    } else if (action == GLFW_RELEASE) {
        keyboardState[key / 64] &= ~(1LL << (key % 64));
    }
}

//Callback para botoes do mouse
void mouseButton(GLFWwindow* window, int button, int action, int mods){
	if(action == GLFW_PRESS){
		if(button == GLFW_MOUSE_BUTTON_LEFT){
			lmbState = 1;			
		}
		
		if(button == GLFW_MOUSE_BUTTON_RIGHT){
			rmbState = 1;			
		}
	}
	
	if(action == GLFW_RELEASE){
		if(button == GLFW_MOUSE_BUTTON_LEFT){
			lmbState = 0;			
		}
		
		if(button == GLFW_MOUSE_BUTTON_RIGHT){
			rmbState = 0;			
		}
	}
	
}

void updateInputStates() {

	rmbSwitch = rmbRecordState ^ rmbState;
	lmbSwitch = lmbRecordState ^ lmbState;
		
   	rmbRecordState = rmbState; 
   	lmbRecordState = lmbState; 

	for (int i = 0; i < STATE_ARRAY_SIZE; i++) {
        keyStateSwitch[i] = keyboardRecordState[i] ^ keyboardState[i];
        keyboardRecordState[i] = keyboardState[i];
    }
}

inline bool rmbDown(){
	return rmbSwitch != 0 && rmbState != 0;	
}

inline bool rmbUp(){
	return rmbSwitch != 0 && rmbState == 0;	
}

inline bool lmbDown(){
	return lmbSwitch != 0 && lmbState != 0;	
}

inline bool lmbUp(){
	return lmbSwitch != 0 && lmbState == 0;	
}

inline bool keyState(int k) {
    return (keyboardState[k / 64] & (1LL << (k % 64))) != 0;
}

inline void setKeyState(int k) {
    keyboardState[k / 64] |= (1LL << (k % 64));
}

inline void unsetKeyState(int k) {
    keyboardState[k / 64] &= ~(1LL << (k % 64));
}

inline bool keyUp(int k) {
    return ((keyStateSwitch[k / 64] & (1LL << (k % 64))) != 0) &&
           ((keyboardState[k / 64] & (1LL << (k % 64))) == 0);
}

inline bool keyDown(int k) {
    return ((keyStateSwitch[k / 64] & (1LL << (k % 64))) != 0) &&
           ((keyboardState[k / 64] & (1LL << (k % 64))) != 0);
}

#endif
