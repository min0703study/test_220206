#include "Stdafx.h"
#include "TempSound.h"

HRESULT TempSound::init(void)
{
	TEMPSOUND->addMp3FileWithKey("����", "Resource");
	return E_NOTIMPL;
}
