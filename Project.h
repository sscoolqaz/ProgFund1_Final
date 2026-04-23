#pragma once

#include "Resource.h"
#include <codecvt>
#include <string>
#include <vector>

using namespace std;

int CreateButton(HWND hWnd, string Label, int xpos, int ypos, int width,
                 int height);
int CreateTextBox(HWND hWnd, int xpos, int ypos, int width, int height,
                  bool userInput, bool vScrollBar, bool hScrollBar);
int CreateLabel(HWND hWnd, string Label, int xpos, int ypos, int width,
                int height);
string ReadStringFromTextBox(int Handle);
int ReadIntFromTextBox(int Handle);
void WriteStringToTextBox(int Handle, string Text);
void AppendStringToTextBox(int Handle, string newText);
void AddLineToTextBox(int Handle, string newLine);
