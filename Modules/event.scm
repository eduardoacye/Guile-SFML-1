(define-module (sfml event)
  #:export (event-make
	    event-type
	    event-size-width
	    event-size-height
	    event-key-code
	    event-key-alt-pressed?
	    event-key-control-pressed?
	    event-key-shift-pressed?
	    event-key-system-pressed?
	    event-mouse-button-code
	    event-mouse-button-x
	    event-mouse-button-y
	    event-mouse-move-x
	    event-mouse-move-y
	    event-mouse-wheel-ticks
	    event-mouse-wheel-x
	    event-mouse-wheel-y))

(load-extension "libguile-sfml" "init_sfml")
