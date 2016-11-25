#if !defined (TrajetCompose_H)
#define TrajetCompose_H

#include "Trajet.hpp"
#include "TrajetSimple.hpp"
#include "TabDynamique.hpp"

class TrajetCompose: public Trajet
{
public:
    TrajetCompose(const TabDynamique* listeDeTrajets);
    TrajetCompose( TrajetCompose const &t);
    const char* getDepart() const;
    const char* getArrivee() const;
    virtual void description() const;
    virtual ~TrajetCompose();
    
    
protected:
    TabDynamique trajets;
};
#endif
