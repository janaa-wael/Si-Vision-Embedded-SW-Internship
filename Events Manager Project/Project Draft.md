# Project Notes

- Event cl
- 2 types of events (HW and System Events)
- each event has a priority
- each event is a class that contains executeEvent()
- executeFunc in 
  - hw events should start with setupHW
  - system events should start with setupSystem
- Event Manager class
  - inserts all events in a container
  - container is priority queue 
  - generates a thread that loops over the priority queue and executes the highest priority event
  - should have
    - postEvent()
    - startHandlingEvents()
    - stopHandlingEvents()
  - must have 1 instance in the program (use Singleton Pattern)
- Event Generator Class
  - generates events & posts them to the Event Manager
  - ctor takes the freq of the event being generated
  - should have generationStart() that creates events randomly
  - should have start() and stop()
  - use factory pattern
    ![image-20250721122941048](C:\Users\hp\AppData\Roaming\Typora\typora-user-images\image-20250721122941048.png)

---------------------------------------

- EventInterface (Abstract Class)

  - SystemEvent & HWEvent inherit EventIf

  - SystemsEvent has 3 child classes

    - has virtual function executeEvent

  - HWEvent has 2 child classes

    - has virtual func executeEvent

  - has priority , id data member

  - virtual functions: executeEvent

  - grandchildren: concrete executeEvent

  - executeFunc

    1- call setUpHardware / setUpSystem
    2- execute events

    

- EventManager

  - data member: priority_queue<int,vector<Events>,comparator/functor>
  - implement functor (in private section), returns event with higher priority
  - startHandlingEvent() --> loop over the container
  - stopHandlingEvents() --> stop thread (called destructor)
  - postEvent: pushes event to the queue
  - Singleton Pattern to create EventManager

- EventGenerator

  - data member: frequency, Event Manager

  - generates event and pushes it in the priority queue

  - ctor --> takes feq of generation

  - generationStart(): creates thread, generates them randomly 

  - map <int,Event*> mp= {(0,new HWSendPacket),(1, HWReceivePacket),()};

    x = rand()%5;

    new mp[x];

mew Dummy();