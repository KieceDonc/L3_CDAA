CREATE TRIGGER insertcontactinteraction AFTER INSERT ON interaction
BEGIN
	UPDATE lastinsert SET lastid = NEW.interactionid WHERE name = "interactionid";
END;
