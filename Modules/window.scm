(define-module (sfml window)
  #:export (window-make
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
