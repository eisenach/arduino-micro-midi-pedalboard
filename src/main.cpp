#include <Arduino.h>
#include <Control_Surface.h> // Include the Control Surface library
#include <MIDI_Interfaces/DebugMIDI_Interface.hpp>
 
// Instantiate a MIDI Debug interface at 115200 baud.
SerialDebugMIDI_Interface<decltype(Serial)> midi_debug{Serial};


CD74HC4067 mux1 {A0, {2, 3, 4, 5}};
CD74HC4067 mux2 {A1, {6, 7, 8, 9}};

// The velocity of the note events
constexpr uint8_t velocity = 0x7F;
constexpr auto channel = CHANNEL_1;

auto note = MIDI_Notes::note(MIDI_Notes::C, 2);

NoteButton buttons[] {
  { mux1.pin(0),  { note++, channel } },
  { mux1.pin(1),  { note++, channel } },
  { mux1.pin(2),  { note++, channel } },
  { mux1.pin(3),  { note++, channel } },
  { mux1.pin(4),  { note++, channel } },
  { mux1.pin(5),  { note++, channel } },
  { mux1.pin(6),  { note++, channel } },
  { mux1.pin(7),  { note++, channel } },
  { mux1.pin(8),  { note++, channel } },
  { mux1.pin(9),  { note++, channel } },
  { mux1.pin(10), { note++, channel } },
  { mux1.pin(11), { note++, channel } },
  { mux1.pin(12), { note++, channel } },
  { mux1.pin(13), { note++, channel } },
  { mux1.pin(14), { note++, channel } },
  { mux2.pin(0),  { note++, channel } },
  { mux2.pin(1),  { note++, channel } },
  { mux2.pin(2),  { note++, channel } },
  { mux2.pin(3),  { note++, channel } },
  { mux2.pin(4),  { note++, channel } },
  { mux2.pin(5),  { note++, channel } },
  { mux2.pin(6),  { note++, channel } },
  { mux2.pin(7),  { note++, channel } },
  { mux2.pin(8),  { note++, channel } },
  { mux2.pin(9),  { note++, channel } },
  { mux2.pin(10), { note++, channel } },
  { mux2.pin(11), { note++, channel } },
  { mux2.pin(12), { note++, channel } },
  { mux2.pin(13), { note++, channel } },
  { mux2.pin(14), { note++, channel  }}
};

void setup() {
  Control_Surface.begin();
  
}

void loop() {
  Control_Surface.loop();
}