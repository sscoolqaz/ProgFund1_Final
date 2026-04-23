#include "BusinessLogic.h"
#include "Project.h"
#include "stdafx.h"
#include <string>
#include <vector>

// THIS IS EXAMPLE CODE - REPLACE WITH YOUR SOLUTION
int Input1Handle;
int Input2Handle;
int ButtonHandle;
int Label1Handle;
int Label2Handle;
int LabelOutput1Handle;
int LabelOutput2Handle;
int Output1Handle;
int Output2Handle;
// END OF EXAMPLE CODE

void InitializeGUI(HWND hWnd) {
  // THIS IS EXAMPLE CODE - REPLACE WITH YOUR SOLUTION
  Label1Handle = CreateLabel(hWnd, "V1", 70, 100, 30, 20);
  Input1Handle = CreateTextBox(hWnd, 100, 100, 400, 20, true, false, false);
  Label1Handle = CreateLabel(hWnd, "V2", 70, 200, 30, 20);
  Input2Handle = CreateTextBox(hWnd, 100, 200, 400, 20, true, false, false);
  ButtonHandle = CreateButton(hWnd, "Do Math", 100, 300, 150, 30);

  LabelOutput1Handle =
      CreateLabel(hWnd, "Result of Multiply", 600, 80, 150, 20);
  Output1Handle = CreateTextBox(hWnd, 600, 100, 400, 150, false, false, true);
  LabelOutput2Handle = CreateLabel(hWnd, "Result of Sum", 600, 280, 150, 20);
  Output2Handle = CreateTextBox(hWnd, 600, 300, 400, 150, false, true, false);
  // END OF EXAMPLE CODE
}

void ProcessInput() {
  // THIS IS EXAMPLE CODE - REPLACE WITH YOUR SOLUTION
  int Value1 = ReadIntFromTextBox(Input1Handle);
  int Value2 = ReadIntFromTextBox(Input2Handle);

  if (ReadStringFromTextBox(Output1Handle) == "") {
    WriteStringToTextBox(Output1Handle, to_string(Value1 * Value2));
  } else {
    string NewResult = ", ";
    NewResult.append(to_string(Value1 * Value2));
    AppendStringToTextBox(Output1Handle, NewResult);
  }

  if (ReadStringFromTextBox(Output2Handle) == "") {
    AppendStringToTextBox(Output2Handle, to_string(Value1 + Value2));
  } else {
    AddLineToTextBox(Output2Handle, to_string(Value1 + Value2));
  }

  // END OF EXAMPLE CODE
}
