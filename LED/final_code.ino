#include <FastLED.h>
#include <Keypad.h>

#define LED_PIN1    31
#define LED_PIN2    32
#define LED_PIN3    33
#define LED_PIN4    34
#define LED_PIN5    35
#define LED_PIN6    36
#define LED_PIN7    37
#define LED_PIN8    38
#define LED_PIN9    39

#define LED_PIN10   40
#define NUM_LEDS    25
#define BRIGHTNESS  64
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
CRGB leds3[NUM_LEDS];
CRGB leds4[NUM_LEDS];
CRGB leds5[NUM_LEDS];
CRGB leds6[NUM_LEDS];
CRGB leds7[NUM_LEDS];
CRGB leds8[NUM_LEDS];
CRGB leds9[NUM_LEDS];
CRGB leds10[NUM_LEDS];
String current_state = "NORMAL";

const byte ROWS = 3; // 4 rows
const byte COLS = 3; // 3 columns

// Define the Keymap
char keys[ROWS][COLS] = {
{'1','2','3'},
{'8','s','4'},
{'7','6','5'},
};
byte rowPins[ROWS] = { 5,6,7 };
byte colPins[COLS] = { 2,3,4 };

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
#define UPDATES_PER_SECOND 100

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;
uint8_t colorIndex;
uint8_t brightness = 255;

void ChangePalettePeriodically();
void FillLEDsFromPaletteColors( uint8_t colorIndex);
void FillTheme1();
void FillTheme2();
void FillTheme3();
void FillTheme4(uint8_t colorIndex);
void FillTheme5();
void FillTheme6();
void FillTheme7();
void FillTheme8();



void setup() {
    delay( 3000 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN1, COLOR_ORDER>(leds1, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN2, COLOR_ORDER>(leds2, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN3, COLOR_ORDER>(leds3, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN4, COLOR_ORDER>(leds4, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN5, COLOR_ORDER>(leds5, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN6, COLOR_ORDER>(leds6, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN7, COLOR_ORDER>(leds7, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN8, COLOR_ORDER>(leds8, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN9, COLOR_ORDER>(leds9, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.addLeds<LED_TYPE, LED_PIN10, COLOR_ORDER>(leds10, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );

    Serial.begin(9600);
    keypad.addEventListener(keypadEvent); //add an event listener for this keypad
    
    currentPalette = RainbowColors_p;
    currentBlending = LINEARBLEND;
}

void loop()
{
//    while ( Serial.available() > 0 ){
      char c= Serial.read();
      if ( c == 'y') {
        current_state = "THEME1";
      }
     else if ( c == 's') {
        current_state = "THEME3";
      }
     else if ( c == 'n') {
        current_state = "THEME2";
      }
//     else if (c == 'o'){
////       current_state = "NORMAL";
//     }
     else if (c == 'p'){
      current_state = "THEME5";
     }
     else if (c == 'q'){
       current_state = "THEME6";
     }
     else if (c == 'r'){
       current_state = "THEME7";
     }
     else if (c == 't'){
       current_state = "THEME8";
     }

     keypad.getKey();

    if(current_state.equals("NORMAL")){
      ChangePalettePeriodically();
      static uint8_t startIndex = 0;
      startIndex = startIndex + 1; /* motion speed */
      FillLEDsFromPaletteColors( startIndex);
    }
    else if(current_state.equals("THEME1")){
      FillTheme1();
    }
    else if(current_state.equals("THEME2")){
      FillTheme2();
    }
    else if(current_state.equals("THEME3")){
      FillTheme3();
    }
    else if(current_state.equals("THEME4")){
      ChangePalettePeriodically();
      static uint8_t startIndex = 0;
      startIndex = startIndex + 1; /* motion speed */
      FillTheme4(startIndex);
    }
    else if(current_state.equals("THEME5")){
      FillTheme5();
    }
    else if(current_state.equals("THEME6")){
      FillTheme6();
    }
    else if(current_state.equals("THEME7")){
      FillTheme7();
    }
    else if(current_state.equals("THEME8")){
      FillTheme8();
    }
    
      FastLED.show();
      FastLED.delay(1000 / UPDATES_PER_SECOND);


     
    }



//take care of some special events
void keypadEvent(KeypadEvent eKey){
switch (keypad.getState()){
 case PRESSED:
   Serial.print("Pressed: ");
   Serial.println(eKey);
   switch(eKey){
    case 's': current_state="NORMAL"; break;
    case '1': current_state="THEME1"; break;
    case '2': current_state="THEME2"; break;
    case '3': current_state="THEME3"; break;
    case '4': current_state="THEME4"; break;
    case '5': current_state="THEME5"; break;
    case '6': current_state="THEME6"; break;
    case '7': current_state="THEME7"; break;
    case '8': current_state="THEME8"; break;
   }
}
}

void FillTheme1(){
  FastLED.clear();
     for( int i = 0; i < NUM_LEDS;i++) {
        if(i%7==2) {
          leds1[i] = CRGB::Red;
          leds10[i] = CRGB::Red;
        }
    }
    for( int i = 0; i < NUM_LEDS;i++) {
        if(i%7==2 || i%7==3) {
           leds2[i] = CRGB::Red;
           leds9[i] = CRGB::Red;
        }
    }
    for( int i = 0; i < NUM_LEDS;i++) {
        if(i%7==5 || i%7==6 || i%7==0) {
        }
        else{
          leds3[i] = CRGB::Red;
          leds8[i] = CRGB::Red;    
        }
    }
    for( int i = 0; i < NUM_LEDS;i++) {
        if(i%7==6 || i%7==0) {
        }
        else{
          leds4[i] = CRGB::Red;
          leds7[i] = CRGB::Red;    
        }
    }
    for( int i = 0; i < NUM_LEDS;i++) {
        if(i%7==1 || i%7==0) {
        }
        else{
          leds5[i] = CRGB::Red;
          leds6[i] = CRGB::Red;    
        }
    }
}
void FillTheme2(){
    FastLED.clear();
     for( int i = 0; i < NUM_LEDS;i++) {
        if(i%7==4) {
          leds1[i] = CRGB::Yellow;
          leds10[i] = CRGB::Yellow;
        }
    }
    for( int i = 0; i < NUM_LEDS;i++) {
        if(i%7==5) {
          leds2[i] = CRGB::Yellow;
          leds9[i] = CRGB::Yellow;
        }
    }
    for( int i = 0; i < NUM_LEDS;i++) {
        if(i%7==6) {
          leds3[i] = CRGB::Yellow;
          leds8[i] = CRGB::Yellow;
          leds4[i] = CRGB::Yellow;
          leds5[i] = CRGB::Yellow;
          leds6[i] = CRGB::Yellow;
          leds7[i] = CRGB::Yellow;
        }
    }
    for( int i = 0; i < NUM_LEDS;i++) {
        if(i%7==1 || i%7==2 || i%7==3) {
          leds4[i] = CRGB::Yellow;
          leds7[i] = CRGB::Yellow;
        }
    }
}
void FillTheme3(){
    FastLED.clear();
    for( int i = 0; i < 25;i++) {
        if(i%8==3 || i%8==7 ){ 
          leds10[i] = CRGB::Yellow;
          leds1[i] = CRGB::Yellow;
        }
    }
     for( int i = 0; i < 25;i++) {
        if(i%8==3 || i%8==4 || i%8==6){ 
          leds9[i] = CRGB::Yellow;
          leds2[i] = CRGB::Yellow;
        }
    }
    for( int i = 0; i < 24;i++) {
        if(i%8==3 || i%8==4 || i%8==5 || i%8==6){ 
          leds8[i] = CRGB::Yellow;
          leds3[i] = CRGB::Yellow;
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%8==3 || i%8==4 || i%8==5){ 
          leds7[i] = CRGB::Yellow;
          leds4[i] = CRGB::Yellow;
        }
    }
    for( int i = 0; i < 24;i++) {
        if(i%8==2 || i%8==1 || i%8==5 || i%8==3 || i%8==4)
          leds6[i] = CRGB::Yellow;
    }
     for( int i = 0; i < 24;i++) {
       if(i%8==2 || i%8==5 || i%8==3 || i%8==4)
          leds5[i] = CRGB::Yellow;
     }
}
void FillTheme4( uint8_t colorIndex_p)
{
    for( int i = NUM_LEDS-1; i >=0 ; i--) {
        leds1[i] = ColorFromPalette( currentPalette, colorIndex_p, brightness, currentBlending);
        leds2[i] = ColorFromPalette( currentPalette, colorIndex_p, brightness, currentBlending);
        leds3[i] = ColorFromPalette( currentPalette, colorIndex_p, brightness, currentBlending);
        leds4[i] = ColorFromPalette( currentPalette, colorIndex_p, brightness, currentBlending);
        leds5[i] = ColorFromPalette( currentPalette, colorIndex_p, brightness, currentBlending);
        leds6[i] = ColorFromPalette( currentPalette, colorIndex_p, brightness, currentBlending);
        leds7[i] = ColorFromPalette( currentPalette, colorIndex_p, brightness, currentBlending);
        leds8[i] = ColorFromPalette( currentPalette, colorIndex_p, brightness, currentBlending);
        leds9[i] = ColorFromPalette( currentPalette, colorIndex_p, brightness, currentBlending);
        leds10[i] = ColorFromPalette( currentPalette, colorIndex_p, brightness, currentBlending);
        colorIndex_p += 1;
    }
}
void FillTheme5(){
    FastLED.clear();
  
     for( int i = 0; i < 25;i++) {
        if(i%7==3  ){ 
          leds9[i] = CRGB::Red;
          leds2[i] = CRGB::Red;
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==2 || i%7==3){ 
          leds8[i] = CRGB::Red;
          leds3[i] = CRGB::Red;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==1 || i%7==2 || i%7==3 ){ 
          leds7[i] = CRGB::Red;
          leds4[i] = CRGB::Red;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==1 || i%7==2 || i%7==3 ){ 
          leds5[i] = CRGB::Red;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if( i%7==1 || i%7==2 || i%7==3 )
          leds6[i] = CRGB::Red;
    }
     for( int i = 0; i < 25;i++) {
        if(i%7 ==0 ){
          leds6[i] = CRGB::Yellow;
          
    }
     }
    
     for( int i = 0; i < 25;i++) {
        if(i%7 ==4){
          leds6[i] = CRGB::Green;
          leds5[i] = CRGB::Green;
    }
     }
    
     
}
void FillTheme6(){
    FastLED.clear();
  
     for( int i = 0; i < 25;i++) {
        if(i%7==4  ){ 
          leds9[i] = CRGB::Pink;
          leds2[i] = CRGB::Pink;
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==3 || i%7==5){ 
          leds8[i] = CRGB::Pink;
          leds3[i] = CRGB::Pink;
          
        }
    }
     for( int i = 0; i < 25;i++) {
        if(i%7==4){ 
          leds8[i] = CRGB::Red;
          leds3[i] = CRGB::Red;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==4 ){ 
          leds7[i] = CRGB::Pink;
          leds4[i] = CRGB::Pink;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==1  ){ 
          leds5[i] = CRGB::Pink;
          leds7[i] = CRGB::Pink;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if( i%7==0 || i%7==2 )
          leds6[i] =CRGB::Pink;
    }
     for( int i = 0; i < 25;i++) {
        if( i%7==1 )
          leds6[i] =CRGB::Red;
    }
    
    
     
}
void FillTheme7(){
    FastLED.clear();
  
    for( int i = 0; i < 25;i++) {
        if(i%7==5){ 
     
          leds2[i] = CRGB::Purple;
          leds9[i] = CRGB::Purple;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==5 || i%7==4){ 
     
          leds3[i] = CRGB::Purple;
          leds8[i] = CRGB::Purple;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==4 || i%7==5 || i%7==3 ){ 
          leds7[i] =  CRGB::Purple;
          leds4[i] =  CRGB::Purple;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==4 || i%7==5 || i%7==3 || i%7==2 ){ 
          leds5[i] = CRGB::Purple;
          leds6[i] = CRGB::Purple;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if( i%7==1){
          leds5[i] =  CRGB::Red;
          leds6[i] =  CRGB::Red;
        }
    }
    for( int i = 0; i < 25;i++) {
        if( i%7==0){
          leds5[i] =  CRGB::Red;
          leds6[i] =  CRGB::Red;
        }
    }
    
    
     
}
void FillTheme8(){
    FastLED.clear();
  
    for( int i = 0; i < 25;i++) {
        if(i%7==2){ 
     
          leds1[i] = CRGB::Green;
          leds5[i] = CRGB::Green;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==2 || i%7==1){ 
     
          leds2[i] = CRGB::Green;
          leds4[i] = CRGB::Green;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==0 || i%7==2 || i%7==1){ 
     
          leds3[i] = CRGB::Green;
          
        }
    }
      for( int i = 0; i < 25;i++) {
        if(i%7==3 || i%7==4 ){ 
     
          leds3[i] = CRGB::Green;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==3){ 
     
          leds6[i] = CRGB::Yellow;
          leds8[i] = CRGB::Yellow;
          
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==4 || i%7==2 ){ 
          leds7[i] =  CRGB::Yellow;
        }
    }
       for( int i = 0; i < 25;i++) {
        if(i%7==3 ){ 
          leds7[i] =  CRGB::Red;
        }
    }
    for( int i = 0; i < 25;i++) {
        if(i%7==1){ 
     
          leds10[i] = CRGB::Yellow;
          leds8[i] = CRGB::Yellow;
          
        }
    }
     for( int i = 0; i < 25;i++) {
        if(i%7==0 || i%7==2 ){ 
          leds9[i] =  CRGB::Yellow;
        }
    }
      for( int i = 0; i < 25;i++) {
        if(i%7==1 ){ 
          leds9[i] =  CRGB::Red;
        }
    }
    
    
     
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    for(int i=0;i<NUM_LEDS;i++){
        leds1[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        leds2[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        leds3[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        leds4[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        leds5[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        leds6[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        leds7[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        leds8[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        leds9[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        leds10[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 8;
    }
}

void ChangePalettePeriodically()
{
    uint8_t secondHand = (millis() / 1000) % 60;
    static uint8_t lastSecond = 99;
    
    if( lastSecond != secondHand) {
        lastSecond = secondHand;
        if( secondHand ==  0)  { currentPalette = RainbowColors_p;         currentBlending = LINEARBLEND; }
        if( secondHand == 10)  { currentPalette = RainbowStripeColors_p;   currentBlending = NOBLEND;  }
        if( secondHand == 15)  { currentPalette = RainbowStripeColors_p;   currentBlending = LINEARBLEND; }
        if( secondHand == 20)  { SetupPurpleAndGreenPalette();             currentBlending = LINEARBLEND; }
        if( secondHand == 25)  { SetupTotallyRandomPalette();              currentBlending = LINEARBLEND; }
        if( secondHand == 30)  { SetupBlackAndWhiteStripedPalette();       currentBlending = NOBLEND; }
        if( secondHand == 35)  { SetupBlackAndWhiteStripedPalette();       currentBlending = LINEARBLEND; }
        if( secondHand == 40)  { currentPalette = CloudColors_p;           currentBlending = LINEARBLEND; }
        if( secondHand == 45)  { currentPalette = PartyColors_p;           currentBlending = LINEARBLEND; }
        if( secondHand == 50)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = NOBLEND;  }
        if( secondHand == 55)  { currentPalette = myRedWhiteBluePalette_p; currentBlending = LINEARBLEND; }
    }
}

void SetupTotallyRandomPalette()
{
    for( int i = 0; i < 16; i++) {
        currentPalette[i] = CHSV( random8(), 255, random8());
    }
}

void SetupBlackAndWhiteStripedPalette()
{
    // 'black out' all 16 palette entries...
    fill_solid( currentPalette, 16, CRGB::Black);
    // and set every fourth one to white.
    currentPalette[0] = CRGB::White;
    currentPalette[4] = CRGB::White;
    currentPalette[8] = CRGB::White;
    currentPalette[12] = CRGB::White;
    
}

// This function sets up a palette of purple and green stripes.
void SetupPurpleAndGreenPalette()
{
    CRGB purple = CHSV( HUE_PURPLE, 255, 255);
    CRGB green  = CHSV( HUE_GREEN, 255, 255);
    CRGB black  = CRGB::Black;
    
    currentPalette = CRGBPalette16(
                                   green,  green,  black,  black,
                                   purple, purple, black,  black,
                                   green,  green,  black,  black,
                                   purple, purple, black,  black );
}

const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM =
{
    CRGB::Red,

 // 'white' is too bright compared to red and blue
    CRGB::Blue,
    CRGB::Black,
    
    CRGB::Red,
    CRGB::Gray,
    CRGB::Blue,
    CRGB::Black,
    CRGB::Red,
    CRGB::Red,
    CRGB::Gray,
    CRGB::Gray,
    CRGB::Blue,
    CRGB::Blue,
    CRGB::Black,
    CRGB::Black
};
