<<<<<<< HEAD
/*
 * selectable_events.js
 */
(function($) {

module("selectable: events");

test("start", function() {
	expect(2);
	el = $("#selectable1");
	el.selectable({
		start: function(ev, ui) {
			ok(true, "drag fired start callback");
			equals(this, el[0], "context of callback");
		}
	});
	el.simulate("drag", 20, 20);
});

test("stop", function() {
	expect(2);
	el = $("#selectable1");
	el.selectable({
		start: function(ev, ui) {
			ok(true, "drag fired stop callback");
			equals(this, el[0], "context of callback");
		}
	});
	el.simulate("drag", 20, 20);
});

})(jQuery);
=======
/*
 * selectable_events.js
 */
(function($) {

module("selectable: events");

test("start", function() {
	expect(2);
	el = $("#selectable1");
	el.selectable({
		start: function(ev, ui) {
			ok(true, "drag fired start callback");
			equals(this, el[0], "context of callback");
		}
	});
	el.simulate("drag", 20, 20);
});

test("stop", function() {
	expect(2);
	el = $("#selectable1");
	el.selectable({
		start: function(ev, ui) {
			ok(true, "drag fired stop callback");
			equals(this, el[0], "context of callback");
		}
	});
	el.simulate("drag", 20, 20);
});

})(jQuery);
>>>>>>> 6686a981138d00e6df8b50ea1054cb770c50da43
