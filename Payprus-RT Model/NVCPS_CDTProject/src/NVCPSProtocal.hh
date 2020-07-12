
#ifndef NVCPSPROTOCAL_HH
#define NVCPSPROTOCAL_HH

#include "umlrtinsignal.hh"
#include "umlrtoutsignal.hh"
#include "umlrtprotocol.hh"
#include "umlrtsignal.hh"
struct UMLRTCommsPort;

namespace NVCPSProtocal
{
    class Base : public UMLRTProtocol
    {
    public:
        Base( const UMLRTCommsPort * & srcPort );
        UMLRTInSignal reqInParameter() const;
        UMLRTInSignal requestIn() const;
        UMLRTOutSignal requestOut() const;
        UMLRTOutSignal requestType( int requestType ) const;
    };
    class Conj : public UMLRTProtocol
    {
    public:
        Conj( const UMLRTCommsPort * & srcPort );
        UMLRTOutSignal reqInParameter( int requestInpara ) const;
        UMLRTOutSignal requestIn() const;
        UMLRTInSignal requestOut() const;
        UMLRTInSignal requestType() const;
    };
    enum SignalId
    {
        signal_reqInParameter = UMLRTSignal::FIRST_PROTOCOL_SIGNAL_ID,
        signal_requestIn,
        signal_requestOut,
        signal_requestType
    };
};

#endif

