#pragma once


typedef void (*event_callback_t) (void*);


typedef struct event_s {
    event_callback_t callback; // The callback function to call
    void* data; // User data of this event (passed as argument of the callback)
    uint32_t timestamp; // The timestamp that indicate the next execution of this event
    uint32_t interval; // The event interval in no ontime (in milliseconds)
    bool ontime; // If this event must be deleted after the first execution
    struct event_s* next; // A pointer to next event in this linked list (can be null)
} *event_t;


class EventsDriver {
    private:

    // Linked list of events
    event_t events;
    uint32_t minNextTimestamp;


    public:

    EventsDriver() {
        this->events = nullptr;
        this->minNextTimestamp = 0;
    }

    event_t addEvent(event_callback_t callback, void* data, uint32_t interval, bool ontime) {
        event_t ev = (event_t) malloc(sizeof(struct event_s));
        ev->callback = callback;
        ev->data = data;
        ev->interval = interval;
        ev->timestamp = millis() + interval;
        ev->ontime = ontime;
        ev->next = events;
        // Insert an event in the linked list and don't care of the order
        events = ev;
        return ev;
    }

    uint32_t processEvents() {
        if (events != nullptr && millis() >= minNextTimestamp) {
            minNextTimestamp = 0xFFFFFFFF;
            event_t ev = events;
            event_t previous = nullptr;

            while (ev) {
                if (millis() >= ev->timestamp) {
                    // Call the callback
                    ev->callback(ev->data);

                    if (ev->ontime) {
                        // Remove the event
                        if (previous == nullptr)
                            events = ev->next;
                        else
                            previous->next = ev->next;
                        free(ev);
                    } else {
                        // Reset the timestamp
                        ev->timestamp = millis() + ev->interval;
                        if (ev->timestamp < minNextTimestamp)
                            minNextTimestamp = ev->timestamp;
                    }
                } else {
                    if (ev->timestamp < minNextTimestamp)
                        minNextTimestamp = ev->timestamp;
                }
                previous = ev;
                ev = ev->next;
            }
        }
        
        return minNextTimestamp;
    }

    void startLoop() {
        while (true) {
            delay(processEvents() - millis());
        }
    }
};
