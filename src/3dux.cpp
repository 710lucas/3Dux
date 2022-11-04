#include "3Dux.h"

void Dux::init(){
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_BOTTOM, NULL);
}

void Dux::update_buttons(){
    hidScanInput();
    kDown = hidKeysDown();
    kHeld = hidKeysHeld();
}

bool Dux::pressed(u32 key){
    return kDown & key;
}

bool Dux::held(u32 key){
    return kHeld & key;
}

// void Dux::begin_render(std::string pos){
//     for(int i = 0; i<pos.length(); i++){
//         pos[i] = tolower(pos[i]);
//     }
//     if(pos == "top"){
//         C3D_RenderTarget* screen = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
//     }
//     if(pos == "bottom"){
//         C3D_RenderTarget* screen = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);
//     }
//     C3D_RenderTarget* screen = C2D_CreateScreenTarget(GFX_TOP, GFX_LEFT);
//     C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
//     C2D_TargetClear(screen, C2D_Color32(0xFF, 0xD8, 0xB0, 0x68));
//     C2D_SceneBegin(screen);
// }
void Dux::begin_render(){
    C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
    C2D_TargetClear(top, C2D_Color32(0xff, 0x00, 0x00, 0x00));
    C2D_SceneBegin(top);
}

void Dux::end_render(){
    C3D_FrameEnd(0);
}

void Dux::end(){

	C2D_Fini();
	C3D_Fini();
	gfxExit();
}