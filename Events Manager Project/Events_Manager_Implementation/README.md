# 🧠 Event Manager System

This project is a multi-threaded, priority-based **Event Manager System** implemented in modern C++. It simulates the generation, scheduling, and execution of system and hardware events, applying the **Singleton Pattern**, **Object-Oriented Design**, and **multithreading** with standard C++11+ libraries.

---

## 📦 Project Structure

### 🔁 EventManager
A singleton class responsible for:
- Managing event queue (priority-based)
- Scheduling and executing events in background threads
- Starting and stopping the event-handling threads automatically

### 🔄 EventGenerator
Periodically creates and posts random events to the `EventManager`:
- Runs in a separate thread
- Supports configurable frequency and total runtime
- Uses `EventFactory` to generate random events

### 🏭 EventFactory
A factory class that generates concrete event objects (e.g., shutdown, wakeup, send packet) based on random type.

### 🧱 Event Hierarchy
All events inherit from a base class `Event`, and are divided into:
- **Hardware Events**
  - `HWSendPacket`
  - `HWReceivePacket`
- **System Events**
  - `SystemWakeup`
  - `SystemSleep`
  - `SystemShutdown`

Each concrete event overrides `executeEvent()`.

---

## 🛠️ Build Instructions

### 🔹 Requirements
- C++11 or higher
- GNU Make
- Linux or Windows (via MinGW)

### 🔸 Compile & Run

```bash
make
./event_manager