
#ifndef TOPCONTROLLERS_HH
#define TOPCONTROLLERS_HH

class UMLRTController;
struct UMLRTCommsPort;
struct UMLRTSlot;

enum CapsuleInstanceId
{
    InstId_Top,
    InstId_Top_Controller,
    InstId_Top_Generator
};
extern UMLRTController * DefaultController;
extern UMLRTCommsPort borderports_Top_Controller[];
extern UMLRTCommsPort internalports_Top_Controller[];
extern UMLRTCommsPort borderports_Top_Generator[];
extern UMLRTCommsPort internalports_Top_Generator[];
extern UMLRTSlot Top_slots[];

#endif

