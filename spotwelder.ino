// The pin number 2 will have a 10k Ohm resistor that pulls pin high when trigger is pressed
// Need to double check trigger wiring
const int SSC = 8;
// This is the digital pin that the Solid State Relay will be conected to.
// High is true or Fire and Low is false or off

void setup()
{
  // put your setup code here, to run once:

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // The serial communication is just to simulate and test the code

  pinMode(trigger, INPUT);
  pinMode(SSC, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:

  int potValue = analogRead(A0); // reads value of analog pin0, 0 is low 1023 is full
  float pulseTime = float(potValue) / 1023;

  // this calculates pulse time in terms of fraction of a second
  // need to verify no problems with variable types int and float
  // This range is way shorter and way longer than it needs to be will edit code during testing

  // Read the input pin:
  int fireTrigger = digitalRead(trigger);
  if (fireTrigger == 1)
  {

    // pre-weld to burn off impurieties like grease, oxydation
    digitalWrite(SSC, HIGH);
    delay(50);
    digitalWrite(SSC, LOW);

    // wait a bit in between pulses
    delay(100);

    digitalWrite(SSC, HIGH);
    Serial.println("Fire__PowertoSSC");
    delay(pulseTime * 1000); // Edited on forum (06/28/2018) fixed mistake: Multiply rather than divide
    digitalWrite(SSC, LOW);
    Serial.println("Fire_OFF");
    delay(3000);
    // This puts a delay to prevent a second pulse and gives time for wires to cool
  }
  else
  {
    digitalWrite(SSC, LOW);
  }

  // print out the value you read:
  Serial.println(pulseTime);
  Serial.println(potValue);
  Serial.println("fireTrigger Value=");
  Serial.println(fireTrigger);

  delay(150); // delay in between reads for stability
}
