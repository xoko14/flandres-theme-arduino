#include "notes.h"

const int buzzer = 6;
int tempo = 1200;

int flandreN[] = {
  F5, D5, A4, F5, D5, A4, F5, D5, A4, E5, E5, E5, F5, D5, A4, F5, D5, A4, F5, D5, A4, G5, G5, G5
};

int flandreT [] = {
  16, 16, 16, 16, 16, 16, 16, 16, 16, 6, 6, 6, 16, 16, 16, 16, 16, 16, 16, 16, 16, 6, 6, 6
};

int flandre2N[] = {
  A4, F4, GS4, E4, B4, GS4, G4, AS4, A4, F4, GS4, E4, B4, GS4, G4, A4, 0, F4, 0, GS4, 0, E4, 0, B4, 0, GS4, 0, G4, 0, AS4, 0, A4, 0, F4, 0, GS4, 0, E4, 0, B4, 0, GS4, 0, G4
};
int flandre2T[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 2, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 2
};

int flandre3N[] = {
  D4, A4, E4, A4, F4, G4, A4, G4, B4, D5, A4, E5, F5, E5, F5, E5, D5, C5, A4, C5, G4, A4, F4
};

int flandre3T[] = {
  4, 4, 4, 4, 4, 8, 8, 4, 4, 8, 8, 8, 8, 8, 16, 16, 8, 8, 8, 8, 8, 8, 2
};

void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  introPlay();
  introPlay();
  tempo = tempo -200;
  aPlay();
  bPlay();
  bPlay();
}

void introPlay(){
  int notesLen = sizeof(flandreN)/sizeof(flandreN[0]);

  for (int thisNote = 0; thisNote < notesLen; thisNote++) {
    int noteDur = tempo / flandreT[thisNote];
    tone(buzzer, flandreN[thisNote], noteDur);
    int notePause = noteDur * 1.45;
    delay(notePause);
    noTone(buzzer);
  }
}

void aPlay(){
  int notesLen = sizeof(flandre2N)/sizeof(flandre2N[0]);

  for (int thisNote = 0; thisNote < notesLen; thisNote++) {
    int noteDur = tempo / flandre2T[thisNote];
    tone(buzzer, flandre2N[thisNote], noteDur);
    int notePause = noteDur * 1.45;
    delay(notePause);
    noTone(buzzer);
  }
}

void bPlay(){
  int notesLen = sizeof(flandre3N)/sizeof(flandre3N[0]);

  for (int thisNote = 0; thisNote < notesLen; thisNote++) {
    int noteDur = tempo / flandre3T[thisNote];
    tone(buzzer, flandre3N[thisNote], noteDur);
    int notePause = noteDur * 1.45;
    delay(notePause);
    noTone(buzzer);
  }
}
