(define-module (sfml rectangle)
  #:export (rectangle-make
	    rectangle-get-size
	    rectangle-get-point-count
	    rectangle-get-point
	    rectangle-get-fill-color
	    rectangle-get-outline-color
	    rectangle-get-outline-thickness
	    rectangle-get-local-bounds
	    rectangle-get-global-bounds
	    rectangle-get-position
	    rectangle-get-rotation
	    rectangle-get-scale
	    rectangle-get-origin
	    rectangle-set-size!
	    rectangle-set-fill-color!
	    rectangle-set-outline-color!
	    rectangle-set-outline-thickness!
	    rectangle-set-position!
	    rectangle-set-rotation!
	    rectangle-set-scale!
	    rectangle-set-origin!
	    rectangle-move!
	    rectangle-rotate!
	    rectangle-scale!))

(load-extension "libguile-sfml" "init_sfml")
