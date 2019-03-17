/*
Copyright (c) 2018 Bryan Hughes <bryan@nebri.us>

This file is part of Raver Lights.

Raver Lights is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Raver Lights is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Raver Lights.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "RVLLogging.h"

RVLLogging::RVLLogging(RVLLoggingInterface* iface, RVLLogLevel level) {
  this->interface = iface;
  this->logLevel = level;
}

void RVLLogging::log(const char *s) {
  this->interface->print(s);
}

template<typename T, typename ...Args> void RVLLogging::log(const char *s, T value, Args ...args) {
  while (*s) {
    if (*s == '%' && *(++s) != '%') {
      this->interface->print(value);
      s++;
      this->log(s, args...);
      return;
    }
    this->interface->print(*(s++));
  }
}

void RVLLogging::error(const char *s) {
  if (this->logLevel >= RVLLogLevel::Error) {
    this->interface->print("[error]: ");
    this->interface->println(s);
  }
}

template<typename T, typename... Args> void RVLLogging::error(const char *s, T value, Args... args) {
  if (this->logLevel >= RVLLogLevel::Error) {
    this->interface->print("[error]: ");
    this->log(s, value, args...);
    this->interface->println();
  }
}

void RVLLogging::info(const char *s) {
  if (this->logLevel >= RVLLogLevel::Info) {
    this->interface->print("[info ]: ");
    this->interface->println(s);
  }
}

template<typename T, typename... Args> void RVLLogging::info(const char *s, T value, Args... args) {
  if (this->logLevel >= RVLLogLevel::Info) {
    this->interface->print("[info ]: ");
    this->log(s, value, args...);
    this->interface->println();
  }
}

void RVLLogging::debug(const char *s) {
  if (this->logLevel >= RVLLogLevel::Debug) {
    this->interface->print("[debug]: ");
    this->interface->println(s);
  }
}

template<typename T, typename... Args> void RVLLogging::debug(const char *s, T value, Args... args) {
  if (this->logLevel >= RVLLogLevel::Debug) {
    this->interface->print("[debug ]: ");
    this->log(s, value, args...);
    this->interface->println();
  }
}
