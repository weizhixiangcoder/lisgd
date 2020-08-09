/*
  distancethreshold: Minimum cutoff for a gestures to take effect
  degreesleniency: Offset degrees within which gesture is recognized (max=45)
  timeoutms: Maximum duration for a gesture to take place in miliseconds
  orientation: Number of 90 degree turns to shift gestures by
  verbose: 1=enabled, 0=disabled; helpful for debugging
  device: Path to the /dev/ filesystem device events should be read from
  gestures: Array of gestures; binds num of fingers / gesturetypes to commands
            Supported gestures: SwipeLR, SwipeRL, SwipeDU, SwipeUD,
                                SwipeDLUR, SwipeURDL, SwipeDRUL, SwipeULDR
*/

unsigned int distancethreshold = 300;
unsigned int degreesleniency = 15;
unsigned int timeoutms = 800;
unsigned int orientation = 0;
unsigned int verbose = 0;
double edgesize_x = 50.0;
double edgesize_y = 50.0;
char *device = "/dev/input/event1";

Gesture gestures[] = {
	/* nfingers  gesturetype  command */
	{ 1,         SwipeLR,     AnyEdge, "xdotool key --clearmodifiers Alt+Shift+e" },
	{ 1,         SwipeRL,     AnyEdge, "xdotool key --clearmodifiers Alt+Shift+r" },
	{ 1,         SwipeDLUR,   AnyEdge, "sxmo_vol.sh up" },
	{ 1,         SwipeURDL,   AnyEdge, "sxmo_vol.sh down" },
	{ 1,         SwipeDRUL,   AnyEdge, "sxmo_brightness.sh up" },
	{ 1,         SwipeULDR,   AnyEdge, "sxmo_brightness.sh down" },
	{ 2,         SwipeLR,     AnyEdge, "xdotool key --clearmodifiers Alt+e" },
	{ 2,         SwipeRL,     AnyEdge, "xdotool key --clearmodifiers Alt+r" },
	{ 2,         SwipeDU,     AnyEdge, "pidof svkbd-sxmo || svkbd-sxmo &" },
	{ 2,         SwipeUD,     AnyEdge, "pkill -9 svkbd-sxmo" },
};
