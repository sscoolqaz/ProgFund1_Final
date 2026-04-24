#include "BusinessLogic.h"
#include "Project.h"
#include "stdafx.h"
#include <invitee.h>

struct GHWND {
  struct {
    int title;
    int first;
    int last;
    int suffix;
    int spouseTitle;
    int spouseLast;
    int spouseFirst;
    int children;
    int street;
    int city;
    int state;
    int zip;
    int inviteeType;
    int eventState;
  } input;

  struct {
    int inStateInvitation;
    int inStateAnnouncement;
    int outStateInvitation;
    int outStateAnnouncement;
    int local;
    int distant;
  } lists;

  int button;
};

GHWND handle;

void InitializeGUI(HWND hWnd) {
  int labelX = 20;
  int inputX = 160;
  int rowSpace = 30;
  int y = 20;

  CreateLabel(hWnd, "Title:", labelX, y, 130, 20);
  handle.input.title =
      CreateTextBox(hWnd, inputX, y, 150, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "First Name:", labelX, y, 130, 20);
  handle.input.first =
      CreateTextBox(hWnd, inputX, y, 150, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Last Name*:", labelX, y, 130, 20);
  handle.input.last =
      CreateTextBox(hWnd, inputX, y, 150, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Suffix:", labelX, y, 130, 20);
  handle.input.suffix =
      CreateTextBox(hWnd, inputX, y, 150, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Spouse Title:", labelX, y, 130, 20);
  handle.input.spouseTitle =
      CreateTextBox(hWnd, inputX, y, 150, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Spouse First:", labelX, y, 130, 20);
  handle.input.spouseFirst =
      CreateTextBox(hWnd, inputX, y, 150, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Spouse Last:", labelX, y, 130, 20);
  handle.input.spouseLast =
      CreateTextBox(hWnd, inputX, y, 150, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Children:", labelX, y, 130, 20);
  handle.input.children =
      CreateTextBox(hWnd, inputX, y, 250, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Street Address*:", labelX, y, 130, 20);
  handle.input.street =
      CreateTextBox(hWnd, inputX, y, 250, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "City*:", labelX, y, 130, 20);
  handle.input.city =
      CreateTextBox(hWnd, inputX, y, 150, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "State*:", labelX, y, 130, 20);
  handle.input.state =
      CreateTextBox(hWnd, inputX, y, 50, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Zip*:", labelX, y, 130, 20);
  handle.input.zip =
      CreateTextBox(hWnd, inputX, y, 100, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Invitee Type:", labelX, y, 130, 20);
  handle.input.inviteeType =
      CreateTextBox(hWnd, inputX, y, 200, 20, true, false, false);
  y += rowSpace;

  CreateLabel(hWnd, "Event State*:", labelX, y, 130, 20);
  handle.input.eventState =
      CreateTextBox(hWnd, inputX, y, 50, 20, true, false, false);
  y += rowSpace;

  handle.button = CreateButton(hWnd, "Submit", labelX, y, 100, 30);
}

void ProcessInput() {}
