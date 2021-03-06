/*
Copyright (c) Bryan Hughes <bryan@nebri.us>

This file is part of RVLLogging.

RVLLogging is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

RVLLogging is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RVLLogging.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Arduino.h>
#include <RVLLogging.h>
#include "./serial_logging.h"

void setup() {
  SerialLogging interface;
  RVLLogging logging(&interface, RVLLogLevel::Info);

  logging.debug("debug");
  logging.info("info");
  logging.error("error");

  logging.debug("debug with number: %d", 42);
  logging.info("info with number: %d", 43);
  logging.error("error with number: %d", 44);

  logging.info("complicated: %d + %f is %s", 30, 42.45, "I dunno");
}

void loop() {
}
