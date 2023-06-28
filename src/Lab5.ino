SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);
uint16_t lowest;
uint16_t highest;
uint16_t current;
uint16_t next;
void setup()
{
    Serial.begin(2500);
    pinMode(D5, OUTPUT);
    pinMode(A5, INPUT);
    lowest = 9900;
    highest = 1;
}
void loop()
{
    current = analogRead(A5);
    lowest = min(lowest, current);
    highest = max(highest, current);
    Serial.println(current);
    int next = map(current, lowest, highest, 0, 255);
    analogWrite(D5, next);
}