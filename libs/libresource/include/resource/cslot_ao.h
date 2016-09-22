#ifndef SEL4_MISC_CSLOT_AO_H
#define SEL4_MISC_CSLOT_AO_H

#include <bedrock/bedrock.h>
#include <bedrock/errx.h> // this module uses errx

void cslot_ao_setup(seL4_CNode root_cnode, seL4_CPtr low, seL4_CPtr high);

seL4_CPtr cslot_ao_alloc(uint32_t count); // TODO: make sure that all users check error conditions

void cslot_ao_dealloc_last(seL4_CPtr ptr);

// these three are necessary because SOMEONE has to know the CSpace layout
// TODO: look at all of the uses of these to make sure they're used properly in the context of errx.
bool cslot_delete(seL4_CPtr ptr);

bool cslot_copy(seL4_CPtr from, seL4_CPtr to);

bool cslot_revoke(seL4_CPtr ptr);

bool cslot_retype(seL4_Untyped ut, int type, int offset, int size_bits, seL4_CPtr slot, int num_objects);

bool cslot_irqget(seL4_IRQControl ctrl, int irq, seL4_CPtr slot);

#endif //SEL4_MISC_CSLOT_AO_H
