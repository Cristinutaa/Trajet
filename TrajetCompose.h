#if !defined (TrajetCompose_H)
#define TrajetCompose_H

#include "Trajet.h"
#include "TrajetSimple.h"
#include "TabDynamique.h"

class TrajetCompose: public Trajet
{
	public:
		TrajetCompose(int t, TabDynamique listeDeTrajets);
        TrajetCompose( TrajetCompose const &t);
		virtual void description() const;
		virtual ~TrajetCompose();


	protected:
		TabDynamique trajets;
		int taille;
};
#endif
