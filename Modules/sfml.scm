(define-module (sfml sfml)
  #:use-module (sfml vector2)
  #:use-module (sfml box)
  #:use-module (sfml color)
  #:use-module (sfml event)
  #:use-module (sfml rectangle)
  #:use-module (sfml window)
  #:export (;; BOX
	    box-make
	    box-get-left
	    box-get-top
	    box-get-width
	    box-get-height
	    box-set-left!
	    box-set-top!
	    box-set-width!
	    box-set-height!
	    box-contains?
	    box-intersects?
	    ;; COLOR
	    color-make
	    color-get-r
	    color-set-r!
	    color-get-g
	    color-set-g!
	    color-get-b
	    color-set-b!
	    color-get-a
	    color-set-a!
	    color-add
	    color-sub
	    color-mod
	    black
	    white
	    red
	    green
	    blue
	    yellow
	    magenta
	    cyan
	    transparent
	    ;; EVENT
	    event-make
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
	    event-mouse-wheel-y
	    ;; RECTANGLE
	    rectangle-make
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
	    rectangle-scale!
	    ;; WINDOW
	    window-make
	    window-get-size
	    window-create
	    window-close
	    window-open?
	    window-poll-event!
	    window-wait-event!
	    window-get-position
	    window-set-position!
	    window-set-size!
	    window-set-title!
	    window-set-visible!
	    window-set-vertical-sync!
	    window-set-mouse-cursos-visible!
	    window-set-key-repeated!
	    window-set-framerate-limit!
	    window-set-active!
	    window-display!
	    window-clear!
	    window-map-pixel-to-coords
	    window-map-coords-to-pixel
	    window-draw-rectangle!
	    mouse-position))

(load-extension "libguile-sfml" "init_sfml")
